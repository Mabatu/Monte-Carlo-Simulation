This project is part of a Monte Carlo simulation that estimates the value of π (Pi). This component focuses on **analyzing** and **visualizing** data collected from repeated simulations. The aim is to demonstrate how the estimate of π becomes more accurate with an increasing number of random iterations using the Monte Carlo method.

## Project Structure

```raw_data```: This folder contains CSV files with raw Pi estimates collected after each iteration. The filenames indicate the number of iterations performed (e.g., `1000.csv`, `1000000.csv`).

```output_plots```: This folder holds plots (Images) that illustrate the estimated value of Pi over the iterations. The files are named according to the number of iterations.

```pi_estimates```: This folder records the estimated values of Pi along with their corresponding iteration counts.

```plot_pi_estimates.R```: This R script reads data from CSV files and generates line plots that compare the estimated values of Pi to the actual value of π.

```plot_error_trend.R```: This R script visualizes how the estimation error decreases as the number of iterations increases (from 1,000 to 100 million).

## How to Use

1. Run simulations to generate raw Pi estimates and save them as CSV files.
2. Use `plot_pi_estimates.R` to generate visualizations comparing the estimated Pi values to the true value.
3. Use `plot_error_trend.R` to analyze how error trends with more iterations.

## Dependencies

- R (version >= 4.0)
- ggplot2
