function p = getParamsMRAC(T, K, Q, gamma_x, gamma_w)
%GETPARAMSMRAC Get params for MRAC Controller
%   Calculates and outputs default parameters for Simulink model
%   params:
%       K - desired static gain
%       T - desired time constant
%       Q - tracking error weight
%       gamma - learning rate
%   Reference model is a first-order object with time constant T and 
%   static gain K

% Reference model G(s) = K/(Ts+1)^3
Num = K;
Den = [T^3 3*T^2 3*T 1];
[Am, Bm, Cm, ~] = tf2ss(Num, Den);

p.Am = rot90(Am,2);
p.Bm = flipud(Bm)*max(Cm);

%get params for small model

% calc your D's
si = [253.74 254.89 212.46 251.93 253.74];
c2 = 0.155; 
R = 2.02;
ke = (1 - c2*R)/si(2);
L = 0.5e-3;
U = 12.95;

Di = (1./si - ke/U)*U/R;

% and then your J's
f45s = [0.6568 0.6270 0.5747 0.1065 0.5044];
w45s = 2*pi*f45s;

Ji = 1./w45s .* (ke./(R+L*w45s) + (R-L*w45s)./(R+L*w45s).*Di);

% calc other params
J = (sum(Ji) - 4*Ji(2))/2;
D = sum(Di) - 4*Di(2);

a = 5;
b = 4.5;
c = 1/J*(ke/R+D);
d = a/J*U/R;

% "True" model - LOC3 linmodel
p.A = [0 1 0;
       0 -a b;
       0 0 -c];

p.B = [0;0;d];

% Regulators - learning rate 
% u(t) = Kr*r(t) + Kx*x(t) - u_ad
p.Kx = place(p.A, p.B, eig(Am)); % State feedback gain for pole placement

p.Kr = p.Kx(1);          % Feedforward gain for ref model matching

p.gamma_x = gamma_x;       % Feedback gain learning rate

% Uncertainty parameters (u_ad - estimate) 
% u_ad = w'*Q
p.Q = Q.*eye(3);                     % tracking error weight
p.gamma_w = gamma_w;         % uncertainty learning rate

% Solve Lyapunov equation for given A and Q

%p.P = sylvester(p.Am', p.Am, -p.Q);

end

