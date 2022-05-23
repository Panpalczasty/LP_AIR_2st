clc
clear all
close all

%% get MRAC params

params = getParamsMRAC(0.5, 1, 10e-8, 0.1, 1);
%% sim 

open mrac_model.slx
sim mrac_model.slx

%% get results


%% plot results

