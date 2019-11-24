double tax(double income) {
	double property[][5] = {
		{0, 23250, 56550, 117950, 256500}, //lower income
		{0.15, 0.28, 0.31, 0.36, 0.398},//tax rate
		{0, 3502.50, 12798.50, 31832.50, 81710.50}//lower tax
	};
	for (int i = 0; i < 5; i++)
	{
		if (income >= property[0][i] && (i == 4 || income <= property[0][i + 1])) {
			double a = (property[2][i] + property[1][i] * (income - property[0][i]));
			return a;

		}

	}
}
