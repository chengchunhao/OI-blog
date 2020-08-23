from html import escape

def Code(flag):
	if flag == 'cpp':
		print('<div class="panel-body"><pre><code class="sh_cpp">',end='')
	if flag == 'python':
		print('<div class="panel-body"><pre><code class="sh_python">',end='')
	while True:
		line = file.readline()
		if not line:
			break
		if line == '```':
			break
		print(escape(line),end='')
	print('</code></pre></div>')
	return

language = input()
file = open('_')
Code('cpp')