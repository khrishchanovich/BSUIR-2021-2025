namespace Project_1;

public partial class ProgressPage : ContentPage
{
    CancellationTokenSource tokenSource = null;
    CancellationToken token;
 

	public ProgressPage()
	{
		InitializeComponent();
	}

    async private void OnStart(object sender, EventArgs e)
    {
        tokenSource= new CancellationTokenSource();
        token= tokenSource.Token;

        label.Text = "In progress...";
        double step = 0.00000001;
        double a = 0, b = 1, sum = 0, n = 100;

        //await Task.Run(() =>
        //{
            for (int i = 0; i <= n; ++i)
            {
                if (token.IsCancellationRequested)
                {
                    return;
                }

                var x = a + i * step;
                sum += Math.Sin(x);

                MainThread.BeginInvokeOnMainThread(() =>
                {
                    progr.Text = $"{i}%";
                    progrBar.Progress = (double)i / 100;
                });
            //Thread.Sleep(50);
            await Task.Delay(50);
            }
       // }, token);

        if (progr.Text != "100%")
            label.Text = "Process is canceled";
        else
            label.Text = sum.ToString();

        tokenSource = null;
    }

    private void OnCancel(object sender, EventArgs e)
    {
        if (tokenSource != null)
        {
            tokenSource.Cancel();
        }
    }
}