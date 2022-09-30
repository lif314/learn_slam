# 评估轨迹的误差
> 预处理任务：轨迹的时间对齐、外参预估

- 问题： 真实估计$T_{gt,i}$和估计轨迹$T_{esti, i}$, 可以定义一些误差指标来评价估计的准确率

- 绝对轨迹误差(Absolute Trajectory Error, ATE)：每个位姿李代数的均方跟误差(Root-Mean-Square Error, RMSE), 可以刻画两条轨迹的旋转和平移误差
$$
ATE_{all} = \sqrt{\frac{1}{N}\sum_{i=1}^{N} \Vert log( \mathbf{T}^{-1}_{gt,i}\mathbf{T}_{esti, i})\Vert_2^2}
$$

- 绝对平移误差(Average Translational Error): trans表示取括号内部变量的平移部分
$$
ATE_{all} = \sqrt{\frac{1}{N}\sum_{i=1}^{N} \Vert trans( \mathbf{T}^{-1}_{gt,i}\mathbf{T}_{esti, i})\Vert_2^2}
$$

- 相对位姿误差(Relative Pose Error, RPE): 考虑$i$时刻和$i+\triangle t$时刻之间的误差
$$
RPE_{all} = \sqrt{\frac{1}{N-\triangle t}\sum_{i=1}^{N-\triangle t} \Vert log\left( (\mathbf{T}^{-1}_{gt,i}\mathbf{T}_{gt, i+\triangle t})^{-1} (\mathbf{T}^{-1}_{esti,i}\mathbf{T}_{esti, i+\triangle t})\right)\Vert_2^2}
$$

- 相对平移误差
$$
RPE_{trans} = \sqrt{\frac{1}{N-\triangle t}\sum_{i=1}^{N-\triangle t} \Vert trans\left( (\mathbf{T}^{-1}_{gt,i}\mathbf{T}_{gt, i+\triangle t})^{-1} (\mathbf{T}^{-1}_{esti,i}\mathbf{T}_{esti, i+\triangle t})\right)\Vert_2^2}
$$