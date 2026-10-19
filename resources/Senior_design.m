clear; clc;

% Sensor position coordinates (x, y) in cm
S1_xy = [5.2, 0];
S2_xy = [10.4, 17];
S3_xy = [0, 17];

% Sensor distance readings (d1, d2, d3) in cm
d1 = .8;
d2 = .3;
d3 = .3;

% Compute angles
[theta_deg, phi_deg, theta_rad, phi_rad] = computeSpatulaTilt(d1, d2, d3, S1_xy, S2_xy, S3_xy);

% Display results
fprintf('--- Output Angles ---\n');
fprintf('Phi   (Roll)  : %8.4f deg  (%8.4f rad)\n', phi_deg, phi_rad);
fprintf('Theta (Pitch) : %8.4f deg  (%8.4f rad)\n', theta_deg, theta_rad);