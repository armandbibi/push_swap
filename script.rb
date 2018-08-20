require 'open3'


x = Integer(ARGV[0])
y = Integer(ARGV[1])
myarray = (0..x).to_a.shuffle.take(x)
median=0;
def nbrelement str, sub
	str.scan(sub).length
end
max = 0
for i in 0..y
	mystring=String.new
	myarray = (0..x).to_a.shuffle.take(x)
	myarray.each do |item|
		mystring.concat(" ").concat(item.to_s)
	end
	push_swap, error_str, status = Open3.capture3('./push_swap', mystring)
	checker, error_str, status = Open3.capture3('./checker', mystring , stdin_data: push_swap)
	puts checker
	p	nbrelement push_swap, "\n"
	if max < (nbrelement push_swap, "\n")
		max = (nbrelement push_swap, "\n")
	end
	k = nbrelement push_swap, "\n"
	median = median + k
	puts error_str
end
median = median / (y + 1)
puts "moyenne: " + median.to_s
puts "max: " + max.to_s
