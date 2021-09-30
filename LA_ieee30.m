%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%   LICHTENBERG ALGORITHM (LA) FOR NONLINEAR UNCONSTRAINED
%                 OPTIMIZATION - TUNED VERSION
%
% AUTHORS: João Luiz Junho Pereira, Guilherme Ferreira Gomes and
% Sebastião Simões;
%
% A fastest Lichtenberg Algorithm(LA) applied to optimization inspired on
% storms with intraclouding radial lightning
%
%Please cite this algorithm as:
%
%PEREIRA, J. L. J. ; FRANCISCO, M. B. ; Diniz, C. A. ; OLIVER, G. A. ; CUNHA JR., S. S. ; GOMES, G. F. . 
%Lichtenberg Algorithm: A Novel Hybrid PHYSICS-Based Meta-Heuristic For Global Optimization. 
%EXPERT SYSTEMS WITH APPLICATIONS, 2020. https://doi.org/10.1016/j.eswa.2020.114522

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
for p = 1:1

format long
tic

set(0,'DefaultAxesFontName', 'Times New Roman')
set(0,'DefaultAxesFontSize', 14)
set(0,'DefaultTextFontname', 'Times New Roman')
set(0,'DefaultTextFontSize', 26)


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

%tranformer tap changing, put manually 

c(21) = 1.1;
c(22) = 1.1;
c(23) = 1.1;
c(24) = 1.1;
d(21) = 0.9;
d(22) = 0.9;
d(23) = 0.9;
d(24) = 0.9;


% Search space
UB = c;       %upper bounds
LB = d;     %lower bounds
d = length(LB);
% Optimizator Parameters
pop = d*10;        %Population
n_iter = 100;      %Max number os iterations/gerations
ref = 0.5;         %if more than zero, a second LF is created with refinement % the size of the other
Np = 10000;       %Number of Particles (If 3D, better more than 10000)
S_c = 0.4;           %Stick Probability: Percentage of particles that can don´t stuck in the
                   %cluster. Between 0 and 1. Near 0 there are more aggregate, the density of
                   %cluster is bigger and difusity is low. Near 1 is the opposite. 
Rc = 75;          %Creation Radius (if 3D, better be less than 80, untill 150)
M = 0;             %If M = 0, no lichtenberg figure is created (it is loaded a optimized figure); if 1, a single is created and used in all iterations; If 2, one is created for each iteration.(creating an LF figure takes about 2 min)
im = 0;            %If zero, no figure is shown on the Matlab screen. If one, yes. 
                   %But only for 2D and 3D

%%%%%TEST FUNCTIONS
%One Vaiable
Fun1 = @(x) PSO_fit_ieee30(x);   %(3)
%Two variables
Fun2 = @(x) (1.5-x(1)*(1-x(2)))^2+(2.25-x(1)*(1-x(2)^2))^2;  % beale's (3,0.5)
%Trhee variables
Fun3 = @(x)  x(1)^2 +x(2)^2 +x(3)^2;           %Schwefel (0,0,0)
%Four variables
Fun4 = @(x)  x(1)^2 +x(2)^2 +x(3)^2 +x(4)^2;   %Schwefel (0,0,0,0)

%Choose the objtective test function and adapt Search Space!
Fun = Fun1; 

[x,fval,iter,state,population]=LA_optimization(Fun,d,im,pop,LB,UB,ref,n_iter,Np,Rc,S_c,M);
toc



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

y =  0.00375*solution_variables.gen(1,2)^2+2*solution_variables.gen(1,2)+0.0175*gen(2,2)^2+1.75*solution_variables.gen(2,2)+0.0625*solution_variables.gen(3,2)^2+1*solution_variables.gen(3,2)...                %cost minimization function
    +0.00834*solution_variables.gen(4,2)^2+3.25*solution_variables.gen(4,2)+0.025*solution_variables.gen(5,2)^2+3*solution_variables.gen(5,2)+0.025*solution_variables.gen(6,2)^2+3*solution_variables.gen(6,2); 


LA_R(1,p) = y;
end