

for p = 1:1
key = 'Vishnu_Sidaarth_(Wroclaw_Uni_SciTech)_[ACADEMIC-SINGLE-USER]';   


networkdata = 'case_ieee30_MIDACOOPF.m';
mpc = loadcase(networkdata);
gen = mpc.gen;
bus = mpc.bus;
gencost = mpc.gencost;
branch = mpc.branch;

Buses = length(bus(:,1));

% Creates the limits for voltage magnitudes %l = number of buses who's
% voltage has to be optimized
l = 6;
for b = 1:l
    c(b)= 1.05;  %voltage upper limit
    d(b)= 0.95;  %voltage lower limit
end

% Creates the limits for generators (Active Power) %m = no of generators
m = 5;
for b = 1:m
    c(l+b)=gen(b+1,9);      %c- uppergenlimits
    d(l+b)=gen(b+1,10);     %d - lowergenlimits
end

% Creates the limits for Var compensators (Reactive Power)
%n is number of var generators 
n = 9;
for b = 1:n
    c(l+m+b)= gen(b+6,4); %c- upperlimits
    d(l+m+b)= gen(b+6,5); %c- lowerlimits
end

%tranformer tap changing

c(21) = 1.1;
c(22) = 1.1;
c(23) = 1.1;
c(24) = 1.1;
d(21) = 0.9;
d(22) = 0.9;
d(23) = 0.9;
d(24) = 0.9;
% c(10) = gen(b,2)/100;
% d(10) = 0; 

problem.func = @problem_function1;

problem.o  = 1; % Number of objectives
problem.n  = length(d); % Number of variables (in total)
problem.ni = 0; % Number of integer variables (0 <= ni <= n)
problem.m  = 0; % Number of constraints (in total)
problem.me = 0; % Number of equality constraints (0 <= me <= m)

problem.xl = d;
problem.xu = c; 
problem.x  = d;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
option.maxeval  = 2000;   
option.maxtime  = 60*60*24;   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
option.printeval  = 0; 

option.save2file  = 0; 

option.param( 1) =  0;  % ACCURACY  
option.param( 2) =  0;  % SEED      
option.param( 3) =  0;  % FSTOP
option.param( 4) =  0;  % ALGOSTOP
option.param( 5) =  0;  % EVALSTOP  
option.param( 6) =  0;  % FOCUS
option.param( 7) =  200;  % ANTS
option.param( 8) =  50;  % KERNEL
option.param( 9) =  0;  % ORACLE    
option.param(10) =  0;  % PARETOMAX   
option.param(11) =  0;  % EPSILON   
option.param(12) =  0;  % BALANCE
option.param(13) =  0;  % CHARACTER  

option.parallel = 1;

[ solution ] = midaco( problem, option, key);

                                    
% bus(1,8) = solution.x(1); %Optimized variables for voltage
% bus(2,8) = solution.x(2);
% bus(5,8) = solution.x(3);
% bus(8,8) = solution.x(4);
% bus(11,8) = solution.x(5);
% bus(13,8) = solution.x(6);
% 
% for n = 1:6          %Optimized variables for Active Power   
%    gen(n,2) = solution.x(6+n)*100;
% end
% 
% for n = 1:size(gen,1)          %Optimized variables for Reactive Power   
%    gen(n,3) = solution.x(12+n)*100;
% end
% 
% branch(11,9) = solution.x(28);
% branch(12,9) = solution.x(29);
% branch(15,9) = solution.x(30);
% branch(36,9) = solution.x(31);
% 
% mpc.version = '2';
% mpc.baseMVA = 100;
% mpc.bus = bus;
% mpc.gen = gen;
% mpc.gencost = gencost;
% mpc.branch = branch;
% mpopt = mpoption('pf.alg', 'NR', 'verbose', 0,'out.all', 0);
% solution_variables = runpf(mpc, mpopt); 


MIDACO_R(1,p) = solution.f;
end 
