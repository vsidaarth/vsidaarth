function [best,fmin,n_iter,state,population]=LA_optimization(Fun,d,im,n,LB,UB,ref,n_iter,Np,Rc,S_c,M)
for i=1:n
    Individuals(i,:)=LB+(UB-LB).*rand(1,d);
    Fitness(i)=Fun(Individuals(i,:));
end
[fmin,I]=min(Fitness);
best=Individuals(I,:);
S=Individuals;
if M==0 || M==1
LF = LA_figure(d,Np,Rc,S_c,M);
end
for t=1:n_iter
    x_start = best;
    X=[];
    if M == 2
    LF = LA_figure(d,Np,Rc,S_c,M);
    end
    scale_factor = 1.2*rand;
    X = LA_points(LF,LB,UB,x_start,scale_factor,d);
    if ref ~=0
    X_local = LA_points(LF,LB*ref,UB*ref,x_start,scale_factor,d);
    end
    for i=1:n
        if ref ~=0
            pop1 = round((0.4)*n);      
            pop2 = n-pop1;              
            S_global = X(randperm(length(X),pop2),:);
            S_ref = X_local(randperm(length(X),pop1),:);
            S = [S_global;S_ref];
        else
            S = X(randperm(length(X),n),:);
        end
        S(i,:)=bound_check(S(i,:),LB,UB);
        Fnew = Fun(S(i,:));
        if (Fnew <= Fitness(i))
            Individuals(i,:) = S(i,:);
            Fitness(i) = Fnew;
        end
        if  Fnew <= fmin
            best = S(i,:);
            fmin = Fnew;
        end
    end
        state(t,:) = [n_iter best fmin];
        population{t} = S;
    if round(t/100) == t/100
        best;
        fmin;
    end
  
    if im == 1 && d == 2  %shows step by step the optimization if ref ~= 0;
        if ref ~=0
        figure(1) 
        set(gcf,'color','w');
        h(1)=plot(best(1,1),best(1,2),'MarkerFaceColor',[1 1 0],'MarkerSize',14,'Marker','pentagram','LineWidth', 0.2, 'LineStyle','none','Color',[0 0 0]);
        hold on
        h(2)=scatter(X_local(:,1),X_local(:,2),2,'MarkerFaceColor','r','MarkerEdgeColor','r','MarkerFaceAlpha',.1,'MarkerEdgeAlpha',.1);
        h(3)=scatter(X(:,1),X(:,2),2,'MarkerFaceColor','b','MarkerEdgeColor','b','MarkerFaceAlpha',.2,'MarkerEdgeAlpha',.2);     
        h(4)=plot(S(2:end,1),S(2:end,2),'MarkerFaceColor',[0 0 0],'MarkerSize',4,'Marker','o','LineStyle','none','Color',[0 0 0]);
        axis([LB(1) UB(1) LB(2) UB(2)]);
        xlabel('x_1')
        ylabel('x_2')
        axis square
        uistack(h(1),'top')
        legend('Lichtenberg Local','Lichtenberg Global','Population','Best','Location','NorthEastOutside')
        hold off
        else        
        figure(1)      %shows step by step the optimization if ref= 0;
        set(gcf,'color','w');
        h(1)=plot(best(1,1),best(1,2),'MarkerFaceColor',[1 1 0],'MarkerSize',14,'Marker','pentagram','LineWidth', 0.2, 'LineStyle','none','Color',[0 0 0]);
        hold on
        h(2)=scatter(X(:,1),X(:,2),2,'MarkerFaceColor','b','MarkerEdgeColor','b','MarkerFaceAlpha',.2,'MarkerEdgeAlpha',.2);   
        h(3)=plot(S(2:end,1),S(2:end,2),'MarkerFaceColor',[0 0 0],'MarkerSize',4,'Marker','o','LineStyle','none','Color',[0 0 0]);
        axis([LB(1) UB(1) LB(2) UB(2)]);
        xlabel('x_1')
        ylabel('x_2')
        axis square
        uistack(h(1),'top')
        legend('Lichtenberg Figure','Population','Best','Location','NorthEastOutside')
        hold off
        end
        pause(0.001)
    end
    if im == 1 && d == 3
        if ref ~=0
        figure(1)   %shows step by step the optimization
        set(gcf,'color','w');
        h(1)=plot3(best(1,1),best(1,2),best(1,3),'MarkerFaceColor',[1 1 0],'MarkerSize',14,'Marker','pentagram','LineWidth', 0.2, 'LineStyle','none','Color',[0 0 0]);
        hold on
        h(2)=scatter3(X_local(:,1),X_local(:,2),X_local(:,3),2,'MarkerFaceColor','r','MarkerEdgeColor','r','MarkerFaceAlpha',.1,'MarkerEdgeAlpha',.1);  
        h(3)=scatter3(X(:,1),X(:,2),X(:,3),2,'MarkerFaceColor','b','MarkerEdgeColor','b','MarkerFaceAlpha',.2,'MarkerEdgeAlpha',.2); 
        h(4)=plot3(S(2:end,1),S(2:end,2),S(2:end,3),'MarkerFaceColor',[0 0 0],'MarkerSize',4,'Marker','o','LineStyle','none','Color',[0 0 0]);
        axis([LB(1) UB(1) LB(2) UB(2) LB(3) UB(3)]);
        xlabel('x_1')
        ylabel('x_2')
        zlabel('x_3')
        axis square
        uistack(h(1),'top')
        legend('Lichtenberg Local','Lichtenberg Global','Population','Best','Location','NorthEastOutside')
        hold off
        else
        figure(1)      %shows step by step the optimization if ref= 0;
        set(gcf,'color','w');
        h(1)=plot3(best(1,1),best(1,2),best(1,3),'MarkerFaceColor',[1 1 0],'MarkerSize',14,'Marker','pentagram','LineWidth', 0.2, 'LineStyle','none','Color',[0 0 0]);
        hold on
        h(2)=scatter3(X(:,1),X(:,2),X(:,3),2,'MarkerFaceColor','b','MarkerEdgeColor','b','MarkerFaceAlpha',.2,'MarkerEdgeAlpha',.2); 
        h(3)=plot3(S(2:end,1),S(2:end,2),S(2:end,3),'MarkerFaceColor',[0 0 0],'MarkerSize',4,'Marker','o','LineStyle','none','Color',[0 0 0]);
        axis([LB(1) UB(1) LB(2) UB(2) LB(3) UB(3)]);
        xlabel('x_1')
        ylabel('x_2')
        zlabel('x_3')
        axis square
        uistack(h(1),'top')
        legend('Lichtenberg Figure','Population','Best','Location','NorthEastOutside')
        hold off
        end
        pause(0.001)
    end
end
disp(['Total number of function evaluation: ',num2str(n_iter)]);
disp(['Best solution (X) = ',num2str(best)]);
disp(['Best Fitness : ',num2str(fmin)]);
end

function s = bound_check(s,LB,UB)
ns_tmp=s;
I=ns_tmp<LB;
ns_tmp(I)=LB(I);
J=ns_tmp>UB;
ns_tmp(J)=UB(J);
s=ns_tmp;
end

function [map]=LA_figure(d,Np,Rc,S,M)

if M==1 || M==2
Rk = Rc*1.1;
add = Rk+2;
particle = 0;
stuck = 0;
escape = 0;
die = 0;
walk = 0;
if d<3 || d>3
map = zeros(((Rk+2)*2));
map(add,add)=1;
    X = 0; x = 0;
    Y = 0; y = 0;
    while (( particle >= Np) + (escape))==0 
    particle=particle+1; 
    phi=rand*2*3.14159265359; 
    X=Rc*cos(phi);
    Y=Rc*sin(phi);
    x=round(X);
    y=round(Y);
    stuck = 0; 
    die = 0;
    while ((stuck+die+escape) == 0)
    walk=rand;
    if walk<.25      
        if map(add+x,add+y+1)==0 
        y=y+1;
        end
    elseif walk<.5    
    	if map(add+x+1,add+y)==0 
        x=x+1;
        end
    elseif walk<.75   
        if map(add+x,add+y-1)==0 
        y=y-1;
        end
    else             
        if map(add+x-1,add+y)==0 
        x=x-1;
        end
    end
    if (hypot(x,y)>=Rk) 
    die=1;
    else
    stuck=0;
            if (map(add+x+1,add+y) + map(add+x-1,add+y) + map(add+x,add+y-1) + map(add+x,add+y+1))~=0 
                if (rand<S) 
                	stuck=1;
                end
            end 
          end 
    end 
    if stuck 
        map(add+x,add+y)=1; 
        stuck=0;
        clf
    if ((hypot(x,y)*1.2)>=Rc)
        escape = 1;
      end 
    end 

    end 
    if (escape==1) 
        disp('The simulation ended before all particle could be tried because boundaries were exceeded');
    end
    return
end
if d==3
map = zeros((2*Rk+4),(2*Rk+4),(2*Rk+4));
map(add,add,add)=1;
    X = 0; x = 0;
    Y = 0; y = 0;
    Z = 0; z=  0;
    while (( particle >= Np) + (escape))==0 
    particle=particle+1; 
    alfa=rand*2*pi;
    beta=rand*2*pi;
    X=Rc*sin(alfa)*cos(beta);
    Y=Rc*sin(alfa)*sin(beta);
    Z=Rc*cos(alfa);
    x=round(X);
    y=round(Y);
    z=round(Z);
    stuck = 0; 
    die = 0;
    while ((stuck+die+escape) == 0)
    walk = 1.5*rand;
    if walk<.25       
        if map(add+x,add+y+1, add+z)==0 
        y=y+1;
        end
    elseif walk<.5    
        if map(add+x+1,add+y, add+z)==0 
        x=x+1;
        end
	elseif walk<.75    
        if map(add+x,add+y-1, add+z)==0 
        y=y-1;
        end
    elseif walk<1      
         if map(add+x-1,add+y, add+z)==0 
         x=x-1;
         end
    elseif walk<1.25   
         if map(add+x,add+y, add+z+1)==0 
         z=z+1;
         end
    else              
        if map(add+x, add+y, add+z-1)==0
        z=z-1;
        end
    end
    if (sqrt(abs(x).^2+abs(y).^2+abs(z).^2)>=Rk) 
    die=1;
    else
    stuck=0;
        	if (map(add+x+1,add+y, add+z) + map(add+x-1,add+y, add+z) + map(add+x,add+y+1, add+z) + map(add+x,add+y-1,add+z) + map(add+x,add+y,add+z+1) + map(add+x,add+y,add+z-1))~=0
            	if (rand<S) 
                	stuck=1;
                end
            end 
        end 
    end 
    if stuck 
     map(add+x,add+y,add+z)=1;
     stuck=0;
     clf
    if (sqrt(abs(x).^2+abs(y).^2+abs(z).^2)*1.2>=Rc)
        escape = 1;
    end 
    end 
    end 
    if (escape==1) 
    	disp('The simulation ended before all particle could be tried because boundaries were exceeded');
    end
end
end
if M==0
    if d<3 | d>3
        load('LFND');
        map=LFND;
    else
        load('LF3D');
        map=LF3D;
    end
end   
end

function [X]=LA_points(K,LB,UB,x0,scale_factor,d)
if d ~= 3
    if d < 3 p=1; else p=3; end
    teta = p*rand;
    for u =1:length(K)
    K(u,1)= K(u,1)*cos(teta)-K(u,2)*sin(teta);
    K(u,2)= K(u,1)*sin(teta)+K(u,2)*cos(teta);
    end
end
if d == 3
    teta = rand; 
    alfa = rand;
    beta = rand;
    for u =1:length(K)
    K(u,1)= K(u,1)*cos(teta)*cos(beta)+K(u,2)*(cos(alfa)*sin(beta)+sin(alfa)*sin(teta)*cos(beta))+K(u,3)*(sin(alfa)*sin(beta)-cos(alfa)*sin(teta)*cos(beta));
    K(u,2)= K(u,1)*(-cos(teta))*sin(beta)+K(u,2)*(cos(alfa)*cos(beta)-sin(alfa)*sin(teta)*sin(beta))+K(u,3)*(sin(alfa)*cos(beta)+cos(alfa)*sin(teta)*sin(beta));
    K(u,3)= K(u,1)*sin(teta)+K(u,2)*(-sin(alfa)*cos(teta))+K(u,3)*cos(alfa)*cos(teta);
    end
end
Xi = zeros(length(K),d);
if d < 4
    for j=1:d
    Xi(:,j) = K(:,j);
    end
end
if d > 3
    for i=1:2:d
          gama = rand; 
          Xi(:,i) = K(:,1)*cos(gama)-K(:,2)*sin(gama);
          Xi(:,i+1) = K(:,1)*sin(gama)+K(:,2)*cos(teta);  
          if mod(d, 2) ~= 0 
              Xi=Xi(:,1:(end-1)); 
          end 
    end
end
for i = 1:d
scale(i) = scale_factor*(UB(i)-LB(i))/(max(Xi(:,i))-min(Xi(:,i)));
Xi(:,i) = scale(i)*Xi(:,i);
end
for i =1:d
    Pcc(i)=(max(Xi(:,i))-min(Xi(:,i)))/2 + min(Xi(:,i));
    Xi(round(length(K)/2),i)= Pcc(i);
    delta(i)=Pcc(i)-x0(i);
end
X=zeros(size(Xi));
for i=1:d
    X(:,i) = Xi(:,i) - delta(i);
end
end
    
