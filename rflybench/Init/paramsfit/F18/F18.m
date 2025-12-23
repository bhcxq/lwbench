clear
% Modeling Full-Envelope Aerodynamics of Small UAVs in Realtime 2010

im=imread('F18_CD.png');
imshow(im);
[x0,y0] = ginput;  %在导入图片中选择坐标轴上点（原点，x轴最大点，y轴最大点，（Xmax,Ymax）
                           %依次选择点后，按Enter键回车
[x1,y1] = ginput;  %沿曲线选择上若干点，回车
figure 
CD_alpha= (x1-min(x0))*360/(max(x0)-min(x0))-180;
CD_y=(y1-max(y0))*2/(min(y0)-max(y0));
plot(CD_alpha, CD_y);
axis([-180, 180, 0, 2]);
%save('CD', 'CD_alpha', 'CD_y')

im=imread('F18_CL.png');
imshow(im);
[x0,y0] = ginput;  %在导入图片中选择坐标轴上点（原点，x轴最大点，y轴最大点，（Xmax,Ymax）
                           %依次选择点后，按Enter键回车
[x1,y1] = ginput;  %沿曲线选择上若干点，回车
figure 
CL_alpha= (x1-min(x0))*360/(max(x0)-min(x0))-180;
CL_y=(y1-max(y0))*4/(min(y0)-max(y0))-2;
plot(CL_alpha, CL_y);
axis([-180, 180, -2, 2]);
%save('CL', 'CL_alpha', 'CL_y')

im=imread('F18_Cm.png');
imshow(im);
[x0,y0] = ginput;  %在导入图片中选择坐标轴上点（原点，x轴最大点，y轴最大点，（Xmax,Ymax）
                           %依次选择点后，按Enter键回车
[x1,y1] = ginput;  %沿曲线选择上若干点，回车
figure 
Cm_alpha= (x1-min(x0))*360/(max(x0)-min(x0))-180;
Cm_y=(y1-max(y0))*1/(min(y0)-max(y0))-0.5;
plot(Cm_alpha, Cm_y);
axis([-180, 180, -0.5, 0.5]);
%save('Cm', 'Cm_alpha', 'Cm_y')

im=imread('F18_CY.png');
imshow(im);
[x0,y0] = ginput;  %在导入图片中选择坐标轴上点（原点，x轴最大点，y轴最大点，（Xmax,Ymax）
                           %依次选择点后，按Enter键回车
[x1,y1] = ginput;  %沿曲线选择上若干点，回车
figure 
CY_alpha= (x1-min(x0))*360/(max(x0)-min(x0))-180;
CY_y=(y1-max(y0))*2/(min(y0)-max(y0))-1;
plot(CY_alpha, CY_y);
axis([-180, 180, -1, 1]);
%save('CY', 'CY_alpha', 'CY_y')