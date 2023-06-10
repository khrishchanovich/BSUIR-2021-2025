namespace Project_1;

public partial class Calculator : ContentPage
{
	int currentFlag = 1;
	string operatorMath;
	double firstNum, secondNum;
    string numberStringFirst = "";
	string numberStringSecond = "";
	string decimalFormat = "N0";

    public Calculator()
	{
		InitializeComponent();
	}

    private void ClickedOnOperation(object sender, EventArgs e)
    {
		Button button = sender as Button;
		currentFlag = -2;
		operatorMath = button.Text;
    }

    private void GetResult(object sender, EventArgs e)
	{ 
		double resultOperation = 0;
		switch (operatorMath)
		{
			case "+":
				resultOperation = firstNum + secondNum;
				break;
			case "-":
                resultOperation = firstNum - secondNum;
                break;
			case "*":
                resultOperation = firstNum * secondNum;
                break;
			case "/":
                resultOperation = firstNum / secondNum;
                break;
        }

		result.Text = string.Empty;
		result.Text = Convert.ToString(resultOperation);
		firstNum = resultOperation;
        numberStringFirst = string.Empty;
        numberStringSecond = string.Empty;
		currentFlag = -1;
    }

    private void ClearAll(object sender, EventArgs e)
    {
		Button button = sender as Button;
		firstNum = 0;
		secondNum = 0;
		currentFlag = 1;
		numberStringFirst= string.Empty;
		numberStringSecond= string.Empty;
		result.Text+= string.Empty;
		result.Text = "0";
    }

    private void MyFunction(object sender, EventArgs e)
    {
		result.Text = Convert.ToString(Math.Pow(10, firstNum));
        numberStringFirst = string.Empty;
        numberStringSecond = string.Empty;
        currentFlag = -1;
		firstNum = Convert.ToDouble(result.Text);
    }

    private void ClearOne(object sender, EventArgs e)
    {
		Button button = sender as Button;
		if (currentFlag == 2)
		{
			numberStringSecond = numberStringSecond.Remove(numberStringSecond.Length - 1, 1);
            if (numberStringSecond != "")
            {
                secondNum = Convert.ToDouble(numberStringSecond);
				result.Text = string.Empty;
				result.Text += numberStringSecond;
			}
			else
			{
				secondNum = 0;
				result.Text = "0";
			}
		}
		else 
		{
			numberStringFirst = numberStringFirst.Remove(numberStringFirst.Length - 1, 1);
            if (numberStringFirst != "")
            {
                firstNum = Convert.ToDouble(numberStringFirst);
				result.Text = string.Empty;
				result.Text += numberStringFirst;
			}
			else
			{
				firstNum = 0;
				result.Text = "0";
			}
		}
    }

    private void ClickedOnNumber(object sender, EventArgs e)
    {
        Button button = sender as Button;
		string numberButton = button.Text;

		if (result.Text == "0" || currentFlag < 0)
		{
			result.Text = string.Empty;
			if (currentFlag < 0)
			{
				currentFlag *= -1;
			}
		}

		if (numberButton == "," && decimalFormat != "N2")
		{
			decimalFormat = "N2";
		}

        result.Text += numberButton;

		if (currentFlag == 1)
		{
			numberStringFirst = numberStringFirst + numberButton;
			firstNum = Convert.ToDouble(numberStringFirst);
        }
		else
		{
			numberStringSecond = numberStringSecond + numberButton;
			secondNum = Convert.ToDouble(numberStringSecond);
        }

    }
}