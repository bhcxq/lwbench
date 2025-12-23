function eul = my_quat2eul(q, varargin)
%MY_QUAT2EUL Convert quaternion to Euler angles, modified from quat2eul.m
%   EUL = QUAT2EUL(QOBJ) converts a quaternion object, QOBJ, into the
%   corresponding Euler angles, EUL.QOBJ is an 4-element vector of quaternion objects.
%   The output, EUL, is an 3-element vector of Euler rotation angles,that is [roll;pitch;yaw]. Rotation angles are in radians.
q = q(:);
if isempty(varargin)
    % Use default rotation sequence
    seq = 'ZXY';
else
    seq = convertStringsToChars(varargin{1});
end
q = robotics.internal.validation.validateQuaternion(q', 'quat2eul', 'q');
%norm_q = sqrt(q' * q);
% if norm_q < 0.5
%     q = [1;0;0;0];
%     norm_q = 1;
% end
%q = q ./ norm_q;
q = robotics.internal.normalizeRows(q);

qw = q(1);
qx = q(2);
qy = q(3);
qz = q(4);

% Pre-allocate output
eul = single(zeros(3, 1,'like',q));
upperSeq = upper(seq);
switch upperSeq
    case 'ZYX'
        % Cap all inputs to asin to 1, since values >1 produce complex
        % results
        % Since the quaternion is of unit length, this should never happen,
        % but some code generation configuration seem to hit this edge case
        % under some circumstances.
        aSinInput = -2 * (qx .* qz - qw .* qy);
        if aSinInput > 1
            aSinInput = single(1);
        elseif (aSinInput < -1)
            aSinInput = -single(1);
        end
        
        eul = [atan2( 2 * (qy .* qz + qw .* qx), qw .^ 2 - qx .^ 2 - qy .^ 2 + qz .^ 2 ); ...
            asin( aSinInput ); ...
            atan2( 2 * (qx .* qy + qw .* qz), qw .^ 2 + qx .^ 2 - qy .^ 2 - qz .^ 2 )];
        
    case 'XYZ'
        % Prevent singularities as done in ZYX case
        % Alternative to rotm2eul(quat2rotm(q), 'XYZ') with fewer
        % operations
        
        % sin(y) = R13 = 2 * (qx*qz + qy*qw)
        % tan(x) = sin(x) / cos(x) = -R23 / R33
        %        = -2 * (qy*qz - qx*qw) / (1 - 2*(qx^2 + qy^2))
        %        = -2 * (qy*qz - qx*qw) / (qw^2 - qx^2 - qy^2 + qz^2)
        % tan(z) = sin(z) / cos(z) = -R12 / R11
        %        = -2 * (qx*qy - qz*qw) / (1 - 2*(qy^2 + qz^2))
        %        = -2 * (qy*qz - qx*qw) / (qw^2 + qx^2 - qy^2 - qz^2)
        
        aSinInput = 2 * (qx .* qz + qy .* qw);
        if aSinInput > 1
            aSinInput = single(1);
        elseif (aSinInput < -1)
            aSinInput = -single(1);
        end
        
        eul = [ atan2( -2 * (qy .* qz - qx .* qw), qw .^ 2 - qx .^ 2 - qy .^ 2 + qz .^ 2 ); ...
            asin( aSinInput ); ...
            atan2( -2 * (qx .* qy - qz .* qw), qw .^ 2 + qx .^ 2 - qy .^ 2 - qz .^ 2 )];
        
    case 'ZXY'
        aSinInput = 2 * (qy .* qz + qw .* qx);
        if aSinInput > 1
            aSinInput = single(1);
        elseif (aSinInput < -1)
            aSinInput = -single(1);
        end
        
        eul = [ asin( aSinInput ); ...
            atan2( -2 * (qx .* qz - qw .* qy), qw .^ 2 - qx .^ 2 - qy .^ 2 + qz .^ 2 ); ...
            atan2( -2 * (qx .* qy - qw .* qz), qw .^ 2 - qx .^ 2 + qy .^ 2 - qz .^ 2 )];
    otherwise
        if coder.target('MATLAB')
            error(message('shared_robotics:robotcore:utils:EulerSequenceNotSupported', ...
                seq, 'ZYX, XYZ, ZXY'));
        else
            assert(false);
        end
end

% Check for complex numbers
if ~isreal(eul)
    eul = real(eul);
end

end

