

for p = 1:1
ObjectiveFunction = @GeneticA_fit_ieee30;


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


nvars = length(d);    % Number of variables
LB = d;   % Lower bound
UB = c;  % Upper bound
options = optimoptions('ga','Display','iter','FunctionTolerance',0.01)
[x,fval] = ga(ObjectiveFunction,nvars,[],[],[],[],LB,UB,[],options);

%% 
bus(1,8) = x(1); %Optimized variables for voltage
bus(2,8) = x(2);
bus(5,8) = x(3);
bus(8,8) = x(4);
bus(11,8) = x(5);
bus(13,8) = x(6);

for n = 1:5          %Optimized variables for Active Power   
   gen(n+1,2) = x(6+n);
end

for n = 1:9          %Optimized variables for Reactive Power   
   gen(n+6,3) = x(12+n);
end

branch(11,9) = x(21);
branch(12,9) = x(22);
branch(15,9) = x(23);
branch(36,9) = x(24);

mpc.version = '2';
mpc.baseMVA = 100;
mpc.bus = bus;
mpc.gen = gen;
mpc.gencost = gencost;
mpc.branch = branch;
mpopt = mpoption('pf.alg', 'NR', 'verbose', 0,'out.all', 0);
solution_variables = runpf(mpc, mpopt); 

GA_R(1,p) = fval;
end


