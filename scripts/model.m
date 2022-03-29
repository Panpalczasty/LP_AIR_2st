%% define model

% calc your D's
si = [253.74 254.89 212.46 251.93 253.74];
R = 3.964;
L = 0.5e-3;
U = 24;
ke = 2.7e-3;

Di = (1./si - ke/U)*U/R;

% and then your J's
f45s = [0.6568 0.6270 0.5747 0.1065 0.5044];
w45s = 2*pi*f45s;

Ji = 1./w45s .* (ke./(R+L*w45s) + (R-L*w45s)./(R+L*w45s).*Di);

% calc other params
J = sum(Ji) - 4*Ji(2);
D = sum(Di) - 4*Di(2);

L = U;
M = [L*J L*D+R*J R*D+ke];

G = tf(L,M);

dz_width = 0.25; %amps

open ../models/model_full.slx
sim ../models/model_full.slx


















