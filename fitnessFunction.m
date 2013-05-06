% Fitness-Function for MatLab Analyse
function z = fitnessFunction(x,y)
z = -20.*exp(-0.2.*sqrt(0.5.*(x.*x+y.*y))) - exp(0.5.*(cos(2.*pi.*x)+cos(2.*pi.*y)))+20+exp(1);
end