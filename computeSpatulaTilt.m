function [theta_deg, phi_deg, theta_rad, phi_rad] = computeSpatulaTilt(d1, d2, d3, S1_xy, S2_xy, S3_xy)
% COMPUTESPATULATILT Calculates pitch (theta) and roll (phi) from 3 distance sensors.
%
% Inputs:
%   d1, d2, d3 : Measured distances from sensors to spatula surface
%   S1_xy      : [x1, y1] coordinates of Sensor 1
%   S2_xy      : [x2, y2] coordinates of Sensor 2
%   S3_xy      : [x3, y3] coordinates of Sensor 3
%
% Outputs:
%   theta_deg, phi_deg : Pitch and roll angles in DEGREES
%   theta_rad, phi_rad : Pitch and roll angles in RADIANS

    % Extract sensor (x, y) coordinates
    x1 = S1_xy(1); y1 = S1_xy(2);
    x2 = S2_xy(1); y2 = S2_xy(2);
    x3 = S3_xy(1); y3 = S3_xy(2);

    %% Step 1: Form plane vectors v1 = S2 - S1 and v2 = S3 - S1
    v1 = [x2 - x1; y2 - y1; d1 - d2];
    v2 = [x3 - x1; y3 - y1; d1 - d3];

    %% Step 2: Cross Product N = v1 x v2
    Nx = (y2 - y1)*(d1 - d3) - (d1 - d2)*(y3 - y1);
    Ny = (d1 - d2)*(x3 - x1) - (x2 - x1)*(d1 - d3);
    Nz = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1);

    N = [Nx; Ny; Nz];

  % Enforce upward-pointing normal vector (+z)
    if N(3) < 0
        N = -N;
    end

    %% Step 3: Normalize N to get unit normal n = [nx; ny; nz]
    n = N / norm(N);
    nx = n(1);
    ny = n(2);
    nz = n(3);

    %% Step 4: Extract Phi (phi) and Theta (theta)
    phi_rad = asin(nx);
    theta_rad = acos(nz / cos(phi_rad));

    %% Convert to Degrees
    phi_deg   = rad2deg(phi_rad);
    theta_deg = rad2deg(theta_rad);
end