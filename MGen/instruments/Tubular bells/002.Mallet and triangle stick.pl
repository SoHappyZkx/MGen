# Main
library = "True Strike Cinematic Orchestral Percussion" # For which library algorithm is optimized
Type = 0 # Instrument type
poly = 100 # Maximum number of simultaneous voices

# Instrument parameters
n_min = "C6" # Lowest note
n_max = "F7" # Highest note
Volume_default = 67 # (direct CC volume, should not be changed by user)

Pedal_import = 1 # 0 - do not import pedal; 1 - import CC64 pedal from source midi file

# Randomization
rnd_vel = 8 # Randomize note velocity not greater than this percent
rand_pos = 8-0 # Randomize note starts-ends not greater than percent of note length 
rand_pos_max = 40-0 # Maximum shift in ms (start-end)

