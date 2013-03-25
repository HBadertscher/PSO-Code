M = csvread('PSO-Data.txt');
p1 = M(:,1:3);
p2 = M(:,4:6);
p3 = M(:,7:9);
p4 = M(:,10:12);
p5 = M(:,13:15);
[x,y] = meshgrid([-10:1:10],[-10:1:10]);
z = x.^2 + y.^2;

%figure;
%contour(x,y,z); 
%hold on;
%plot(p1(:,1),p1(:,2),p2(:,1),p2(:,2),p3(:,1),p3(:,2),p4(:,1),p4(:,2),p5(:,1),p5(:,2));
%figure;
%plot3(p1(:,1),p1(:,2),p1(:,3),p2(:,1),p2(:,2),p2(:,3),p3(:,1),p3(:,2),p3(:,3),p4(:,1),p4(:,2),p4(:,3),p5(:,1),p5(:,2),p5(:,3));

figure;
for i=1 : 1 : size(M,1)
	contour(x,y,z);
    hold on; 
    plot(p1(i,1),p1(i,2),'o',p2(i,1),p2(i,2),'o',p3(i,1),p3(i,2),'o',p4(i,1),p4(i,2),'o',p5(i,1),p5(i,2),'o');
    axis([-10 10 -10 10]);
    hold off;
    pause(0.2);
end
