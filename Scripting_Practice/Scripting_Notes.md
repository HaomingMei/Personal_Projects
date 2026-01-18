## Script Usage
- Data collection
- Data Cleaning
- Analysis
- Visualization
- Calibration
- Automation
- Note: Use MATLAB for signal processing
- Plot/Visualization Notes:
    -Remember to convert the units
    - label every axis
    - Title
    - grid?
    - legend
### Data Control
Expect Unclean ata
- Missing Samples
- NaNs/ Inf
- Out of range values
- Sensor warm-up artifacts

## General Script Structure
- load_data (fetch it)
- validate_data (remove the bad ones)
- process_data (apply filters/correction)
    - Remove bias
    - Apply filters
    - Correction
- plot_data

## When do I use CSV vs pandas
- CSV are low-level, it's generic and for simple data
- Pandas are used when convience matters more, since vectorization and column operations are available using pandas

## Json?

