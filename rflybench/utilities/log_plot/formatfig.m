function formatfig(fontsize, w, h)
%设置全局字体大小为18
figure_FontSize = fontsize;
% set(get(gca,'XLabel'),'FontSize',figure_FontSize,'Vertical','top');
% set(get(gca,'YLabel'),'FontSize',figure_FontSize,'Vertical','middle');
% set(findobj('FontSize',10),'FontSize',figure_FontSize);
%设置figure在屏幕上顺序排列显示
%w:图片宽，像素
ssize = get(0, 'ScreenSize'); %获取显示器尺寸
allfigs = findobj(get(groot, 'Children'), 'Type', 'figure' );
nx = floor(ssize(3) / w);
ny = floor((ssize(4)) / (h));
for i = 1 : size(allfigs, 1)
    for j = 1 : size(allfigs, 1)
        if allfigs(j).Number == i
            fig = allfigs(j);
            break;
        end
    end
    n = mod(i, nx * ny); if n == 0; n = nx * ny; end
    nnx = mod(n, nx); if nnx == 0; nnx = nx; end
    nny = floor((n - 1) / nx);
    set(fig, 'position', [(nnx - 1) * w, ssize(4) - (nny + 1) * (h + 90), w, h]);
end
end

