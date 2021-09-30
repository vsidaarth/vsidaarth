   function [y] = GeneticA_fit_ieee30(x)
   
networkdata = 'case_ieee30_MIDACOOPF.m';
mpc = loadcase(networkdata);
branch = mpc.branch;
bus = mpc.bus;
gen = mpc.gen;
gencost = mpc.gencost;

%% Solve for independent variables
mpc.version = '2';
%-----  Power Flow Data  -----%
%system MVA base


bus(1,8) = x(1);    %Optimized variables for gen bus voltages  
bus(2,8) = x(2);
bus(5,8) = x(3);
bus(8,8) = x(4);
bus(11,8) = x(5);
bus(13,8) = x(6);
      

for n = 1:5          %Optimized variables for Active Power   
   gen(n+1,2) = x(6+n);
end

for n = 1:9        %Optimized variables for Reactive Power   
   gen(n+6,3) = x(12+n);
end

branch(11,9) = x(21);
branch(12,9) = x(22);
branch(15,9) = x(23);
branch(36,9) = x(24);




mpc.baseMVA = 100;
mpc.bus = bus;
mpc.gen = gen;
mpc.gencost = gencost;
mpc.branch = branch;


mpopt = mpoption('pf.alg', 'NR', 'verbose', 0,'out.all', 0);
solution_variables = runpf(mpc, mpopt);
   
    y = 0.00375*solution_variables.gen(1,2)^2+2*solution_variables.gen(1,2)+0.0175*gen(2,2)^2+1.75*solution_variables.gen(2,2)+0.0625*solution_variables.gen(3,2)^2+1*solution_variables.gen(3,2)...                %cost minimization function
    +0.00834*solution_variables.gen(4,2)^2+3.25*solution_variables.gen(4,2)+0.025*solution_variables.gen(5,2)^2+3*solution_variables.gen(5,2)+0.025*solution_variables.gen(6,2)^2+3*solution_variables.gen(6,2);