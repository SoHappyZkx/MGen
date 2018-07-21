rules_file = rules2\rules.csv # Specify which file contains all rules

lclimax_notes = 13 # Local climax: Highest note in higher voice within 13 notes or 8 measures - which is smaller
lclimax_mea = 8 # Local climax: Highest note in higher voice within 13 notes or 8 measures - which is smaller

show_ignored_flags = 0 # Show even ignored flags (with strikethrough in rules.xlsm)
show_allowed_flags = 0 # Show even allowed flags (bold in rules.xlsm)
show_min_severity = 0 # Minimum severity to highlight note

# 0 - Show only rule name up to colon. Show only subrules starting with colon
# 1 - Add subrules without colon
# 2 - Add rule comments
ly_rule_verbose = 2 

# Rule parameters
fill_steps_mul = 2 # Multiply number of notes between leap notes to get steps for filling (+2)
first_steps_tonic = 3 # Number of first steps, which must contain tonic note (will increase by one if cantus is longer than 10 notes)

show_hatch = 0 # 0 - show no hatch, 1 = show dissonance hatch, 2 = show msh hatch
harm_notation = 1 # Harmonic notation (see configs/harm/harm-notation.csv for details)
show_harmony_bass = 2 # 0 = do not show bass, 1 = Show harmony bass, 2 = Show chord type (6 or 64)
show_severity = 1 # =1 to show severity and flag id in square brackets in comments to notes (also when exporting to MIDI file)
