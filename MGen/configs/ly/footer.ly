\markup { 
  \vspace #2
  \bold Legend:
} 

\markup {
  \line {
  \vspace #1
    \column {
      \char ##x2461
      \bold 4:3
 \raise #0.3 \teeny \override #`(direction . ,UP) { \dir-column {
        \with-color #(rgb-color 0.2 0.995 0.000) \circle 7
 } }
    \hspace #5
      
 \raise #0.3 \teeny \override #`(direction . ,UP) { \dir-column {
        \with-color #(rgb-color 0.988 0.005 0.000) \underline \circle 8
 } }
    \hspace #5
      \raise #0.9 \circle \note #"1" #1
      \raise #0.9 \musicglyph #"noteheads.s2xcircle"
      \raise #0.9 \musicglyph #"noteheads.s0harmonic"
    }
    \hspace #5
    \column {
      "Voice number (2) is shown before note"
      "For each note bar number (4) and croche beat (3) is shown"
      "This note violates minor rule (green). If underlined, means that violation"
      "is shown in the score with shape of same color"
      "This note violates major rule (red). If underlined, means that violation"
      "is shown in the score with shape of same color"
      "This note was corrected"
      "This note is a dissonance"
      "This note is considered passing or auxiliary"
    }
  }
} 

