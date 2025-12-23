function q = my_eul2quat(eul, varargin)
%MY_EUL2QUAT Convert Euler angle to quaternion, modified from eul2quat.m
%   Q = EUL2QUAT(EUL) converts a given Euler angle, EUL, into
%   the corresponding unit quaternion, Q. EUL is a 3-by-1 vector of Euler
%   rotation angles.
%   The output, Q, is a 4-by-1 vector. The quaternion is of the form q = [w x y z]T, with w as the scalar number.

if isempty(varargin)
    % Use default rotation sequence
    seq = 'ZXY';
else
    seq = convertStringsToChars(varargin{1});
end

% Pre-allocate output
q = zeros(4, 1, 'like', eul);
q(1) = 1;
c = cos(eul / 2);
s = sin(eul / 2);

upperSeq = upper(seq);
switch upperSeq
    case 'ZYX'
        % Construct quaternion
        q = [c(3) .* c(2) .* c(1) + s(3) .* s(2) .* s(1); ...
            c(3) .* c(2) .* s(1) - s(3) .* s(2) .* c(1); ...
            c(3) .* s(2) .* c(1) + s(3) .* c(2) .* s(1); ...
            s(3) .* c(2) .* c(1) - c(3) .* s(2) .* s(1)];
        
    case 'XYZ'
        % Construct quaternion
        q = [c(1) .* c(2) .* c(3) - s(1) .* s(2) .* s(3); ...
            s(1) .* c(2) .* c(3) + c(1) .* s(2) .* s(3); ...
            -s(1) .* c(2) .* s(3) + c(1) .* s(2) .* c(3); ...
            c(1) .* c(2) .* s(3) + s(1) .* s(2) .* c(3)];
        
    case 'ZXY'
        q = [c(3) * c(1) * c(2) - s(3) * s(1) * s(2);
            c(3) * s(1) * c(2) - s(3) * c(1) * s(2);
            c(3) * c(1) * s(2) + s(3) * s(1) * c(2);
            s(3) * c(1) * c(2) + c(3) * s(1) * s(2)];
    otherwise
        if coder.target('MATLAB')
            error(message('shared_robotics:robotcore:utils:EulerSequenceNotSupported', ...
                seq, 'ZYX, XYZ, ZXY'));
        else
            assert(false);
        end
end

end

