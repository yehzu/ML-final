function out = auc(rk, label)


[srk, sidx] = sort(rk);
slb = label(sidx);

tp = 0; fp = 0; area = 0;
i = 1;
while i ~= length(rk)+1
	t = 0;
	f = 0;
	p = srk(i);
	while (i ~= length(rk)+1) && (srk(i) == p)
		if slb(i) == 1
			t = t + 1;
		else
			f = f + 1;
		end
		i = i+1;
	end

	if (f > 0) 
		area = area + (tp+tp+t) * f * 0.5;
	end
	tp = tp + t;
	fp = fp + f;
end

if tp == 0 || fp == 0
	out = 0;
else
	out = area / tp / fp;
end

out = 1-out;

