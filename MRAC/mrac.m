clc
clear all
close all

%% get MRAC params

params = getParamsMRAC(0.25, 1, 10e-3, 10e-5, 100);
%% sim 

open mrac_model.slx
sim mrac_model.slx

%% get results


%% plot results

