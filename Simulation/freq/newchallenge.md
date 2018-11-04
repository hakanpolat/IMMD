#### Analyzing a signal using FFT
1. Go to [the folder](https://github.com/mesutto/IMMD/tree/master/Simulation/freq) and observe the file "mydata.xlsx" with the required data.
2. The first column corresponds to the sample number and the second column corresponds to the value of the signal on each sample.
3. Import the data to MATLAB. Plot the signal against time. The sampling frequency is 25600 Hz.
4. Can you make a guess on the fundamental frequency of the signal by just looking at the plot? Hint: Check the periodicity of the signal.
5. Now, using the whole data as the FFT window, obtain the frequency spectrum of the signal. What is the fundamental frequency? What is the value of the fundamental component? (Plot the spectrum up to 5 kHz.)
6. What is the DC component of the signal? Hint: You may obtain this with a much simpler method.
7. Plot the spectrum against harmonic numbers this time (not against frequency). What are the orders and values of the most dominant harmonics?
8. What is the frequency resolution of the FFT? Hint: How many cycles does your window have?
9. Are there any inter-harmonics? If yes, what are the frequency and amplitude values?
10. Now, using only one fundamental cycle as the FFT window, obtain and plot the spectrum. Can you obtain the harmonic values properly? What about the inter-harmonics? Comment on the result. Hint: What is the frequency resolution of the new FFT?
11. Using the signal, use fourier series expansion to obtain the values of the dominant harmonics obtained before (obtain the fourier series coefficiencts using MATLAB).
