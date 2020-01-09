\ProvidesClass{template}

\LoadClass[twocolumn, a4paper]{ctexart}

% 两栏间距
\setlength{\columnsep}{16pt}

% 分割线
\setlength{\columnseprule}{0.3pt}

% 目录深度
\setcounter{tocdepth}{4}

% 中文目录
\renewcommand{\contentsname}{\centerline{目~~~~录}}

% 页边距
\RequirePackage[inner=2cm, outer=1.5cm, top=2.5cm, bottom=2.5cm]{geometry}

% 列表间距
\RequirePackage{enumitem}
\setenumerate[1]{itemsep=0pt, partopsep=0pt, parsep=\parskip, topsep=0pt}
\setitemize[1]{itemsep=0pt, partopsep=0pt, parsep=\parskip, topsep=0pt}

% 页眉页脚
\RequirePackage{fancyhdr}
\renewcommand{\headrulewidth}{0pt}
\fancyhead{}
\fancyfoot[C]{\textit{\thepage}}
\pagestyle{fancy}

% 颜色
\RequirePackage{xcolor}

% 数学公式
\RequirePackage{amsmath}
\RequirePackage{amsthm}
\RequirePackage{amsfonts}
\RequirePackage{mathptmx}

% 表格
\RequirePackage{booktabs}
\RequirePackage{multirow}

% 超链接
\RequirePackage{hyperref}
\hypersetup{
	colorlinks=true,
	urlcolor=blue,
	linkcolor=black
}

% 表格、图片浮动
\RequirePackage{stfloats}

% 字体
\setmainfont{Times New Roman}
\setCJKmonofont{SimHei}
\setmonofont{Consolas}

% 代码高亮
\RequirePackage{listings}
\lstset{
	columns = fixed,
	breaklines = true,
	tabsize = 4,
	frame = lines,
	columns = fullflexible,
	commentstyle = \color[RGB]{0,128,0},
	keywordstyle = \color{blue}\bfseries,
	basicstyle   = \small\ttfamily,
	stringstyle  = \color{purple}\ttfamily,
	rulesepcolor = \color{red!20!green!20!blue!20},
	showstringspaces = false
}

\lstdefinestyle{py}{
	language = python
}

\lstdefinestyle{cpp}{
	language = c++
}