function R = my_eul2rotm(eul, varargin)
%EUL2ROTM Convert Euler angles to rotation matrix
%   R = EUL2ROTM(EUL) converts a given Euler angles, EUL, into the
%   corresponding rotation matrix, R. EUL is an 3-by-1 vector of Euler rotation
%   angles. The output, R, is an 3-by-3-by rotation matrix. Rotation angles are input in radians.

if isempty(varargin)
    % Use default rotation sequence
    seq = 'ZXY';
else
    seq = convertStringsToChars(varargin{1});
end

% Pre-allocate output
R = zeros(3,3,'like',eul);
ct = cos(eul);
st = sin(eul);

upperSeq = upper(seq);
switch upperSeq
    case 'ZYX'
         %     The rotation matrix R can be constructed as follows by
        %     ct = [cx cy cz] and st = [sx sy sz]
        %
        %     R  = Rz(tz) * Ry(ty) * Rx(tx)
        
        R(1,1) = ct(2)*ct(3);
        R(1,2) = st(1)*st(2)*ct(3) - ct(1)*st(3);
        R(1,3) = ct(1)*st(2)*ct(3) + st(1)*st(3);
        R(2,1) = ct(2)*st(3);
        R(2,2) = st(1)*st(2)*st(3) + ct(1)*ct(3);
        R(2,3) = ct(1)*st(2)*st(3) - st(1)*ct(3);
        R(3,1) = -st(2);
        R(3,2) = st(1)*ct(2);
        R(3,3) = ct(1)*ct(2);
        
    case 'XYZ'
       %     The rotation matrix R can be constructed as follows by
        %     ct = [cx cy cz] and st = [sx sy sz]
        %
        %     R = [            cy*cz,           -cy*sz,     sy]
        %         [ cx*sz + cz*sx*sy, cx*cz - sx*sy*sz, -cy*sx]
        %         [ sx*sz - cx*cz*sy, cz*sx + cx*sy*sz,  cx*cy]
        %       = Rx(tx) * Ry(ty) * Rz(tz)
        
        R(1,1) = ct(2).*ct(3);
        R(1,2) = -ct(2).*st(3);
        R(1,3) = st(2);
        R(2,1) = ct(1).*st(3) + ct(3).*st(1).*st(2);
        R(2,2) = ct(1).*ct(3) - st(1).*st(2).*st(3);
        R(2,3) = -ct(2).*st(1);
        R(3,1) = st(1).*st(3) - ct(1).*ct(3).*st(2);
        R(3,2) = ct(3).*st(1) + ct(1).*st(2).*st(3);
        R(3,3) = ct(1).*ct(2);
        
    case 'ZXY'
        %     The rotation matrix R can be constructed as follows by
        %     ct = [cx cy cz] and st = [sx sy sz]
        %
        %     R  = Rz(tz) * Rx(tx) * Ry(ty)
        
        R(1,1) = ct(3)*ct(2) -st(3)*st(1)*st(2);
        R(1,2) = - ct(1)*st(3);
        R(1,3) = ct(2)*st(3)*st(1) + ct(3)*st(2);
        R(2,1) = ct(2)*st(3) + ct(3)*st(1)*st(2);
        R(2,2) = ct(3)*ct(1);
        R(2,3) = st(3)*st(2) - ct(3) *ct(2)*st(1);
        R(3,1) = -ct(1)*st(2);
        R(3,2) = st(1);
        R(3,3) = ct(2)*ct(1);
    otherwise
        if coder.target('MATLAB')
            error(message('shared_robotics:robotcore:utils:EulerSequenceNotSupported', ...
                seq, 'ZYX, XYZ, ZXY'));
        else
            assert(false);
        end
end

end

