%对比px4_simulink_app_params.c文件中参数和实飞参数

% 读取默认参数
file1 = fileread('.\mainModel\px4_simulink_app_params.c');
% 读取实飞参数
file2 = fileread('D:\Project\Liftingwing\Model\model_240826_matlab2023\log\FLY\20240830\log_53_2024-9-5-18-23-28\log_53_2024-9-5-18-23-28.txt');

% 正则表达式提取文件1中的参数名和值
pattern1 = 'PARAM_DEFINE_FLOAT\((\w+),\s*([-+]?\d*\.?\d+|[-+]?\d+)f\);';
tokens1 = regexp(file1, pattern1, 'tokens');
params1 = containers.Map;
for i = 1:length(tokens1)
    params1(tokens1{i}{1}) = str2double(tokens1{i}{2});
end

% 正则表达式提取文件2中的参数名和值
pattern2 = '(\w+),([\d.\-]+)';
tokens2 = regexp(file2, pattern2, 'tokens');
params2 = containers.Map;
for i = 1:length(tokens2)
    params2(tokens2{i}{1}) = str2double(tokens2{i}{2});
end

% 设置容差值
tolerance = 1e-6;

% 准备表格数据
paramNames = {};
valuesFile1 = [];
valuesFile2 = [];

% 比较两个文件中的参数
allKeys1 = keys(params1);
for i = 1:length(allKeys1)
    key = allKeys1{i};
    if isKey(params2, key)
        value1 = params1(key);
        value2 = params2(key);
        if abs(value1 - value2) > tolerance
            paramNames{end+1} = key; %#ok<SAGROW>
            valuesFile1(end+1) = value1; %#ok<SAGROW>
            valuesFile2(end+1) = value2; %#ok<SAGROW>
        end
    end
end

% 创建表格并显示
T = table(paramNames', valuesFile1', valuesFile2', 'VariableNames', {'Parameter', '默认', '实飞'});
disp(T);
