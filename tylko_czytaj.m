% Czytanie danych PV 
clear all
close all
load danePV2012-2018.mat

% T_RES - timestamp

%  MONO    POLY    CIGS
% F_442   F_474   F_973  - frequency [Hz]  
% I_442   I_474   I_973  - current [A]
% P_442   P_474   P_973  - power [W]
% U_442   U_474   U_973  - voltege [V]

% IS_040  IS_612  IS_734 - Irradiation [W/m^2]    
% TA_040  TA_612  TA_734 - Ambient temp. [celc. grad.]
% TM_040  TM_612  TM_734 - Module temp.  [celc. grad] 
% WV_040  WV_612  WV_734 - Wind veloc. [m/s]

plot(P_973)
datestr(T_RES(1))
datestr(T_RES(end))
datetime_pwr = datetime(T_RES, 'ConvertFrom', 'datenum', 'Format', 'dd-MM-yy HH:mm');