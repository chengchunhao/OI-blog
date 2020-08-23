#include <bits/stdc++.h>
using std::endl;
using std::ifstream;
using std::ofstream;

std::string IN, OUT, line;

int main() {
	int i;
	bool del = false, strong = false, I = false, math1 = false, math2 = false;
	std::cin >> IN >> OUT;
	ifstream in(IN);
	ofstream out(OUT);
	out << "<!DOCTYPE html>" << endl;
	out << "<html lang=\"zh-cn\">" << endl;
	out << "	<head>" << endl;
	out << "		<meta charset=\"utf-8\" />" << endl;
	out << "		<script type=\"text/javascript\">uojHome = \"https://uoj.ac\"</script>" << endl;
	out << "		<link type=\"text/css\" rel=\"stylesheet\" href=\"http://uoj.ac/css/bootstrap.min.css?v=2015.5.31\" />" << endl;
	out << "		<link type=\"text/css\" rel=\"stylesheet\" href=\"http://uoj.ac/css/bootstrap-theme.min.css?v=2015.5.31\" />" << endl;
	out << "		<script src=\"https://uoj.ac/js/jquery.min.js\"></script>" << endl;
	out << "		<link type=\"text/css\" rel=\"stylesheet\" href=\"https://uoj.ac/css/sh_typical.min.css\" />" << endl;
	out << "		<script src=\"https://uoj.ac/js/sh_main.min.js\"></script><script type=\"text/javascript\">$(document).ready(function(){sh_highlightDocument()})</script>" << endl;
	out << "		<script src=\"mathjax-config.js\" defer></script>" << endl;
	out << "		<script type=\"text/javascript\" id=\"MathJax-script\" async" << endl;
	out << "		src=\"https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js\">" << endl;
	out << "		</script>" << endl;
	out << "	</head>" << endl;
	out << "	<body>" << endl;
	while (getline(in, line)) {
		if (line.size() >= 3 && line[0] == '`' && line[1] == '`' && line[2] == '`') {
			ofstream outcode("_");
			while (getline(in, line)) {
				if (line.size() >= 3 && line[0] == '`' && line[1] == '`' && line[2] == '`') break;
				outcode << line << endl;
			}
			system("python trans-code.py > __");
			ifstream incode("__");
			while (getline(incode, line)) out << line << endl;
		} else {
			out << "<p>";
			for (i = 0; i < line.size(); ++i) {
				if (i + 1 < line.size() && line[i] == '~' && line[i + 1] == '~') {
					if (!del) del = true, out << "<del>";
					else del = false, out << "</del>";
					++i;
				} else if (line[i] == '*' && !math1 && !math2) {
					if (!I) I = true, out << "<i>"; 
					else I = false, out << "</i>";
				} else if (i + 1 < line.size() && line[i] == '*' && line[i + 1] == '*') {
					if (!strong) strong = true, out << "<strong>"; 
					else strong = false, out << "</strong>";
					++i;
				} else {
					out << line[i];
					if (line[i] == '&') {
						if (i + 1 < line.size() && line[i + 1] == '&') math2 ^= 1, ++i;
						else math1 ^= 1;
					}
				}
			}
			out << "</p>" << endl;
		}
	}
	out << "	</body>" << endl;
	out << "</html>" << endl;
	system("rm _");
	system("rm __");
	return 0;
}
