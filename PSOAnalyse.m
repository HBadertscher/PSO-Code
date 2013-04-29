M = csvread('PSO-Data.txt');
p1 = M(:,1:3);
p2 = M(:,4:6);
p3 = M(:,7:9);
p4 = M(:,10:12);
p5 = M(:,13:15);
p6 = M(:,16:18);
p7 = M(:,19:21);
p8 = M(:,22:24);
p9 = M(:,25:27);
p10 = M(:,28:30);
[x,y] = meshgrid([-10:0.1:10],[-10:0.1:10]);
z = fitnessFunction(x,y);

% figure;
% surf(x,y,z); 
% hold on;
% plot(p1(:,1),p1(:,2),p2(:,1),p2(:,2),p3(:,1),p3(:,2),p4(:,1),p4(:,2),p5(:,1),p5(:,2));
% figure;
% plot3(p1(:,1),p1(:,2),p1(:,3),p2(:,1),p2(:,2),p2(:,3),p3(:,1),p3(:,2),p3(:,3),p4(:,1),p4(:,2),p4(:,3),p5(:,1),p5(:,2),p5(:,3));

figure;
for i=1 : 1 : size(M,1)
   surf(x,y,z);
   hold on; 
   plot(p1(i,1),p1(i,2),'o',p2(i,1),p2(i,2),'o',p3(i,1),p3(i,2),'o',p4(i,1),p4(i,2),'o',p5(i,1),p5(i,2),'o',p6(i,1),p6(i,2),'o',p7(i,1),p7(i,2),'o',p8(i,1),p8(i,2),'o',p9(i,1),p9(i,2),'o',p10(i,1),p10(i,2),'o');
%   plot3(p1(i,1),p1(i,2),fitnessFunction(p1(i,1),p1(i,2)),'o', p2(i,1),p2(i,2),fitnessFunction(p2(i,1),p2(i,2)),'o', p3(i,1),p3(i,2),fitnessFunction(p3(i,1),p3(i,2)),'o', p4(i,1),p4(i,2),fitnessFunction(p4(i,1),p4(i,2)),'o', p5(i,1),p5(i,2),fitnessFunction(p5(i,1),p1(i,2)),'o',p6(i,1),p6(i,2),fitnessFunction(p6(i,1),p6(i,2)),'o',p7(i,1),p7(i,2),fitnessFunction(p7(i,1),p7(i,2)),'o',p8(i,1),p8(i,2),fitnessFunction(p8(i,1),p8(i,2)),'o',p9(i,1),p9(i,2),fitnessFunction(p9(i,1),p9(i,2)),'o',p10(i,1),p10(i,2),fitnessFunction(p10(i,1),p10(i,2)),'o');
   axis([-10 10 -10 10]);
   hold off;
%   pause(0.2);
    pause
end
