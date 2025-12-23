function [data_f, data_P1] = my_fft(data)
data_fft = fft(data);
L = length(data_fft);
data_P2 = abs(data_fft / L);
data_P1 = data_P2(1 : fix(L / 2) + 1);
data_P1(2 : end - 1) = 2 * data_P1(2 : end - 1);
data_f = 250 * (0 : fix(L / 2)) / L;
end