clear all
clc

%Please ensure all required files are in the directory
%% MeteoBlue 
load('radiation_2012_2020H.mat');
datenum_mb = SWP.TimeStamp;
dswr_mb = SWP.DirectShortwaveRadiation;
load('temperature_2012_2020H.mat');
temp_mb = SWP.Temperature;
load('cloud_2012_2020H.mat');
cloud_mb = SWP.CloudCoverTotal;

%converting datenum to datetime for having a look! 

datetime_mb = datetime(datenum_mb, 'ConvertFrom', 'datenum', 'Format', 'dd-MM-yy HH');

%data will be considered from 01-01-17 00 - 10-03-21 23

datetime_mb_forecast = datetime_mb(1465:80568);
dswr_mb_forecast = dswr_mb(1465:80568);
temp_mb_forecast = temp_mb(1465:80568);


%% PWr K1/38 PV system 

load('PV_RES10_11032021.mat');
datetime_pwr = datetime(T_RES, 'ConvertFrom', 'datenum', 'Format', 'dd-MM-yy HH:mm');

%data will be considered from 01-01-17 00 - 01-01-21 00 (%254339 %464728)
%01-01-17 00 - 02-01-18 00 (%254339 %307043)

dswr_pwr = IS_040(254339:464728);
temp_pwr = TA_040(254339:464728);
P_pwr = P_442(254339:464728);
F_pwr = F_442(254339:464728);

%Now the data are synced but the meteoblue is 1hr resolution and pwr data
%has a 10 min resolution. Hence, we average the pwr data for every hour. 

S  = numel(dswr_pwr);
xx = reshape(dswr_pwr(1:S - mod(S, 6)), 6, []);
y  = sum(xx, 1).' / 6;
dswr_pwr = y;

S  = numel(temp_pwr);
xx = reshape(temp_pwr(1:S - mod(S, 6)), 6, []);
y  = sum(xx, 1).' / 6;
temp_pwr = y;

S  = numel(P_pwr);
xx = reshape(P_pwr(1:S - mod(S, 6)), 6, []);
y  = sum(xx, 1).' / 6;
P_pwr = y;

S  = numel(F_pwr);
xx = reshape(F_pwr(1:S - mod(S, 6)), 6, []);
y  = sum(xx, 1).' / 6;
F_pwr = y;


%now to concatenate all the values

variables = horzcat(dswr_mb_forecast, temp_mb_forecast, dswr_pwr, temp_pwr, F_pwr);
% variables = variables(logical(variables(:,5)),:);

% indices = find(variables(:,5)==0);
% variables(indices,:) = [];

%create timetable 

% time_table =  array2timetable(variables, 'RowTimes', datetime_mb_forecast);
% 
% updated_timetable = time_table;
% writetimetable(updated_timetable);
% type 'updated_timetable.txt';

%1st column = datetime
%2nd column = meteoblue forecast for irradiation
%3rd column = meteoblue forecast for temperature
%4th column = PWr irradiation
%5th column = PWr temperature
%6th column = PWr power

%% for Narasimha RAO
load('PV_RES10_11032021.mat');
datetime_pwr = datetime(T_RES, 'ConvertFrom', 'datenum', 'Format', 'dd-MM-yy HH');

%data will be considered from %01-01-17 00 - 02-01-18 00 (%254339 %307043)



P_pwr = P_442(254339:307043);
wind_velocity = WV_040(254339:307043);

S  = numel(P_pwr);
xx = reshape(P_pwr(1:S - mod(S, 6)), 6, []);
y  = sum(xx, 1).' / 6;
P_pwr = y;
P_pwr = P_pwr/1000;


S  = numel(wind_velocity);
xx = reshape(wind_velocity(1:S - mod(S, 6)), 6, []);
y  = sum(xx, 1).' / 6;
wind_velocity = y;

%cut in speed is 2 m/s so everything below that is 0
% we use turbine https://www.ryse.energy/5kw-wind-turbines/

%for speeds between 2m/s and 13 m/s we use a straight line formula 
wind_velocity = wind_velocity*4;
wind_velocity(wind_velocity < 2) = 0
wind_power = (4.2*wind_velocity - 8.4)/13;
wind_power(wind_power < 0) = 0;
wind_power(wind_power > 4.2) = 4.2;

variables = horzcat(P_pwr,wind_power);

%datetime creation 
first = datetime(2017, 1, 1);
last = datetime(2018, 1, 2);
datetime_NR = first:hours(1):last;
datetime_NR.Format='dd-MM-yyyy HH:mm';
datetime_NR = transpose(datetime_NR);
time_table_NR_Rao =  array2timetable(variables, 'RowTimes', datetime_NR);
writetimetable(time_table_NR_Rao);

%% 3 years data

Timestamp = (datetime('2017-01-01 00:00:00') : -minutes(15) : datetime('2021-01-01 00:00:00')).';
Timestamp.Format = 'yyyy-MM-dd HH:mm:ss';

type 'time_table_NR_Rao.txt';
