

min=1;
max=11 % ONLY ODD NUMBERS
cen=(min+max)/2;
np=25;
count=np;
npconst=count;
separationdis=0.4; % MUST BE MULTIPLE OF MAX-1
s=separationdis;
stickcoeffnum=1;
stickcoeffden=10;

stickarr1=1:1:stickcoeffnum;
stickarr1=stickarr1*2;
stickarr2=1:1:stickcoeffden-stickcoeffnum;
stickarr2=(stickarr2*2)+1;
stickarr=horzcat(stickarr1,stickarr2);

upwar= min:s:max;
dowar= max:-s:min;
upwar=upwar';
dowar=dowar';

minarr=ones(((max-1)/s)+1,1);
maxarr=max*ones(((max-1)/s)+1,1);

%FRONT WALL
leftwallf=horzcat(minarr,upwar,minarr);
rightwallf=horzcat(maxarr,upwar,minarr);
downwallf=horzcat(upwar,minarr,minarr);
upwallf=horzcat(upwar,maxarr,minarr);

%BACK WALL
leftwallb=horzcat(minarr,upwar,maxarr);
rightwallb=horzcat(maxarr,upwar,maxarr);
downwallb=horzcat(upwar,minarr,maxarr);
upwallb=horzcat(upwar,maxarr,maxarr);

%CONNECTOR WALLS
leftwalldc=horzcat(minarr,minarr,upwar);
leftwalluc=horzcat(minarr,maxarr,upwar);
rightwalluc=horzcat(maxarr,maxarr,upwar);
rightwalldc=horzcat(maxarr,minarr,maxarr);

% Removing Double Entries
leftwalldc(max,:)=[];
leftwalldc(1,:)=[];
leftwalluc(max,:)=[];
leftwalluc(1,:)=[];
rightwalluc(max,:)=[];
rightwalluc(1,:)=[];
rightwalldc(max,:)=[];
rightwalldc(1,:)=[];
upwallf(max,:)=[];
upwallf(1,:)=[];
downwallf(max,:)=[];
downwallf(1,:)=[];
upwallb(max,:)=[];
upwallb(1,:)=[];
downwallb(max,:)=[];
downwallb(1,:)=[];

% FRACAGG DEFINITION
fracagg=ones(np,3);
fracagg(1,:)=[cen cen cen];

% JUMP SELECTION LIST
randsel=vertcat(leftwallf,rightwallf,upwallf,downwallf,leftwallb,rightwallb,upwallb,downwallb,leftwalldc,leftwalluc,rightwalluc,rightwalldc);
len=1;
e=2;
flag=0;
flag2=0;
flag3=0;
p=1;

while p~=np
    
rvar=randi([1 4*max+8*(max-2)],1,1);
dot=randsel(rvar,:);
p;
dot;
count;
np;

while count~=0
    
ravrd=randi([1 26],1,1);
randstick=randi([1 stickcoeffden],1,1);

              for r=1:1:len
               c=fracagg(r,:);
               if  sqrt((dot(1)-c(1))^2+(dot(2)-c(2))^2+(dot(3)-c(3))^2)==separationdis
                  flag=1; % STUCK
               if rem(stickarr(randstick),2)==0 % STICK PROBABILITY
                   flag4=1;
               end
        
               end
    
               if dot(1)-c(1)==0&&dot(2)-c(2)==0&&dot(3)-c(3)==0
                 flag2=1; % DOUBLE PARTICLE
               end
    
               end
    

    if flag==1
       break;
    end
        
    % JUMPS IN SAME PLANE
    if ravrd==1
    dot(2)=dot(2)-s;
   
    end

    if ravrd==2
    dot(3)=dot(3)-s;
    dot(2)=dot(2)-s;
   
    end

    if ravrd==3
    dot(3)=dot(3)+s;
    
    end

    if ravrd==4
    dot(3)=dot(3)+s;
    dot(2)=dot(2)+s;
    
    end

    if ravrd==5
    dot(2)=dot(2)+s;
    
    end

    if ravrd==6
    dot(2)=dot(2)+s;
    dot(3)=dot(3)+s;
    
    end

    if ravrd==7
    dot(3)=dot(3)+s;
    
    end

    if ravrd==8
    dot(3)=dot(3)+s;
    dot(2)=dot(2)-s;

    end
    
    % JUMPS TO MOVE IN ADJACENT LEFT PLANE 
    
    if ravrd==9
        dot(1)=dot(1)-s;
    end
    
    if ravrd==10
        dot(1)=dot(1)-s;
        dot(2)=dot(2)-s;
    end
    
    if ravrd==11
        dot(1)=dot(1)-s;
        dot(2)=dot(2)-s;
        dot(3)=dot(3)-s;
    end
    
    if ravrd==12
        dot(1)=dot(1)-s;
        dot(3)=dot(3)-s;
    end
    
    if ravrd==13
        dot(1)=dot(1)-s;
        dot(2)=dot(2)+s;
        dot(3)=dot(3)-s;
    end
    
    if ravrd==14
        dot(1)=dot(1)-s;
        dot(2)=dot(2)+s;
    end
    
    if ravrd==15
        dot(1)=dot(1)-s;
        dot(2)=dot(2)+s;
        dot(3)=dot(3)+s;
    end
    
    if ravrd==16
        dot(1)=dot(1)-s;
        dot(3)=dot(3)+s;
    end
    
    if ravrd==17
        dot(1)=dot(1)-s;
        dot(2)=dot(2)-s;
        dot(3)=dot(3)+s;
    end
    
    % JUMP TO MOVE INTO ADJACENT RIGHT PLANE
    
    if ravrd==18
        dot(1)=dot(1)+s;
    end
    
    if ravrd==19
        dot(1)=dot(1)+s;
        dot(2)=dot(2)-s;
    end
    
    if ravrd==20
        dot(1)=dot(1)+s;
        dot(2)=dot(2)-s;
        dot(3)=dot(3)+s;
    end
    
    if  ravrd==21
        dot(1)=dot(1)+s;
        dot(3)=dot(3)+s;
    end
    
    if ravrd==22
        dot(1)=dot(1)+s;
        dot(2)=dot(2)+s;
        dot(3)=dot(3)+s;
    end
    
    if ravrd==23
        dot(1)=dot(1)+s;
        dot(2)=dot(2)+s;
    end
    
    if ravrd==24
        dot(1)=dot(1)+s;
        dot(2)=dot(2)+s;
        dot(3)=dot(3)-s;
    end
    
    if ravrd==25
        dot(1)=dot(1)+s;
        dot(3)=dot(3)-s;
    end
    
    if ravrd==26
        dot(1)=dot(1)+s;
        dot(2)=dot(2)-s;
        dot(3)=dot(3)-s;
    end
    


% Step moved after above
dot

   if dot(1)<min||dot(1)>max||dot(2)<min||dot(2)>max||dot(3)<min||dot(3)>max
    flag3=1; %OUT OF BOUNDS
    break;
   end


end

p=p+1;



if flag==1&&flag2==1
    np=np+1;
    flag=0;
    flag2=0;
end


if flag==1
fracagg(e,:)=dot;
e=e+1;
flag=0;
count=count-1;
len=len+1;
flag4=0;
x=fracagg(:,1);
y=fracagg(:,2);
z=fracagg(:,3);
scatter3(x,y,z,'filled');
axis([min max min max min max])
end


if flag3==1
    np=np+1;
    flag3=0;
end
        

end




