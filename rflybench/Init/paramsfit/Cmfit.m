im=imread('Cm.png');
imshow(im);
[x0,y0] = ginput;  %在导入图片中选择坐标轴上点（原点，x轴最大点，y轴最大点，（Xmax,Ymax）
                           %依次选择点后，按Enter键回车
[x1,y1] = ginput;  %沿曲线选择上若干点，回车
figure 
Cm_alpha= (x1-min(x0))*400/(max(x0)-min(x0))-200;
Cm_y=(y1-max(y0))*7/(min(y0)-max(y0))-3;
plot(Cm_alpha, Cm_y);
axis([-200, 200, -3, 4]);
save('Cm', 'Cm_alpha', 'Cm_y')
