im=imread('Cl.png');
imshow(im);
[x0,y0] = ginput;  %在导入图片中选择坐标轴上点（原点，x轴最大点，y轴最大点，（Xmax,Ymax）
                           %依次选择点后，按Enter键回车
[x1,y1] = ginput;  %沿曲线选择上若干点，回车
figure 
CL_alpha= (x1-min(x0))*400/(max(x0)-min(x0))-200;
CL_y=(y1-max(y0))*3/(min(y0)-max(y0))-1.5;
plot(CL_alpha, CL_y);
axis([-200, 200, -1.5, 1.5]);
save('CL', 'CL_alpha', 'CL_y')
