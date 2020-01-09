{{ self.title() }}

{{ s('description') }}

点独立集是图论中的概念。一个点独立集是一个图中一些两两不相邻的顶点的集合，亦即一个由顶点组成的集合 $S$，使得 $S$ 中任两个顶点之间没有边。顿顿设计了一个在无向图上求解点独立集的算法，希望你可以帮他实现一下。

### 算法框架

1. 对于给定的无向图，不断地使用“归约规则”缩减图的规模，直至无法继续使用为止。

2. 当无法使用归约规则时，每次“贪心”地选取一个顶点直接从图中删去，直至能继续使用归约规则或图为空。

3. 反复迭代上述步骤，直至图为空。

### 归约规则

每成功地执行一次规约规则，会将一个顶点选入答案中，选入的顶点按下面的规则唯一确定：

1. 若图中有顶点度为 0，则将其中编号最小的选入答案中，并把它从图中删去；

2. 否则若图中有顶点度为 1，则将其中编号最小的选入答案中，并把它和它唯一的邻接顶点从图中删去；

3. 否则不能成功执行规约规则。

### 贪心策略

当图中不存在度小于 2 的顶点时，需要从图中贪心地删去一个顶点，被删去的顶点按下面的策略唯一确定：

1. 若图中度最大的顶点唯一，则把它从图中删去；

2. 否则，在上述顶点中，选择这样的顶点，使得删去它之后，图中剩余的度为 1 的顶点最多。若这样的顶点唯一，则把它从图中删去；

3. 否则，在这样的顶点中，选择编号最大的那个从图中删去。

{{ s('input format') }}

{{ self.input_file() }}

输入第一行包含用空格分隔的两个正整数 $n$ 和 $m$，表示图中有 $n$ 个顶点、$m$ 条无向边，顶点编号从 $1$ 到 $n$。

接下来 $m$ 行，每行包含用空格分隔的两个正整数 $u$ 和 $v$，表示编号为 $u$ 和 $v$ 的两个顶点间有一条无向边。输入数据保证所有的顶点编号（$u$、$v$ 和 $w$）均为 $[1,n]$ 范围内的正整数，保证 $u \ne v$ 且同一条边不会出现多次。

{{ s('output format') }}

{{ self.output_file() }}

按求解顺序输出该点独立集（即每成功地执行归约规则一次就输出一个被选入的顶点），每行输出一个顶点编号。

{{ s('sample') }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

{{ img('Picture1.png', size = 0.4, align = 'middle', inline = True) }}

输出 $v_{10}$，删去 $v_{10}$、$v_9$。

{{ img('Picture2.png', size = 0.4, align = 'middle', inline = True) }}

删去 $v_5$。

{{ img('Picture3.png', size = 0.5, align = 'middle', inline = True) }}

输出 $v_6$，删去 $v_6$、$v_7$。

{{ img('Picture4.png', size = 0.5, align = 'middle', inline = True) }}

输出 $v_8$，删去 $v_8$。

{{ img('Picture5.png', size = 0.5, align = 'middle', inline = True) }}

删去 $v_3$。

{{ img('Picture6.png', size = 0.5, align = 'middle', inline = True) }}

输出 $v_1$，删除 $v_1$、$v_2$。

{{ img('Picture7.png', size = 0.5, align = 'middle', inline = True) }}

输出 $v_4$，删除 $v_4$。

{{ s('subtasks') }}

共有四个子任务，每个子任务均包含一个或多个测试点。若你的程序对一个子任务的**全部**测试点，都能给出正确的输出，则得该子任务的满分，否则该子任务得 $0$ 分。本题满分共计 $100$ 分。

子任务一（${{ data[0].score }}$ 分）：输入数据保证 $n \le {{ tools.hn(prob.args['subn']) }}$ 且 $m \le {{ tools.hn(prob.args['subm']) }}$，且图中没有环。

子任务二（${{ data[1].score }}$ 分）：输入数据保证 $n \le {{ tools.hn(prob.args['subn']) }}$ 且 $m \le {{ tools.hn(prob.args['subm']) }}$，且对于任意三个不同顶点 $u$、$v$ 和 $w$，如果 $u$ 和 $v$ 之间有边且 $v$ 和 $w$ 之间有边，则 $u$ 和 $w$ 之间有边。

子任务三（${{ data[2].score }}$ 分）：输入数据保证 $n \le {{ tools.hn(prob.args['subn']) }}$ 且 $m \le {{ tools.hn(prob.args['subm']) }}$。

子任务四（${{ data[3].score }}$ 分）：输入数据保证 $n \le {{ tools.hn(prob.args['n']) }}$ 且 $m \le {{ tools.hn(prob.args['m']) }}$。

{{ s('hint') }}

本题输入输出数据量较大，请选择合理方式进行读写。

