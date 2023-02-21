(G-CODE GENERATED BY FLATCAM v8.992 - www.flatcam.org - Version Date: 2020/05/03)

(Name: Phoenix612_Stage_3_PA_Testing_v1.drl_cnc-17)
(Type: G-code from Excellon)
(Units: MM)

(Created on Friday, 13 January 2023 at 14:01)

(This preprocessor is the default preprocessor used by FlatCAM.)
(It is made to work with MACH3 compatible motion controllers.)


(TOOLS DIAMETER: )
(Tool: 1 -> Dia: 0.7)
(Tool: 2 -> Dia: 0.75)
(Tool: 3 -> Dia: 0.8)
(Tool: 4 -> Dia: 0.9)
(Tool: 5 -> Dia: 1.0)
(Tool: 6 -> Dia: 1.1)
(Tool: 7 -> Dia: 1.2)
(Tool: 8 -> Dia: 1.5)
(Tool: 9 -> Dia: 1.7)

(FEEDRATE Z: )
(Tool: 1 -> Feedrate: 30.0)
(Tool: 2 -> Feedrate: 30.0)
(Tool: 3 -> Feedrate: 30.0)
(Tool: 4 -> Feedrate: 30.0)
(Tool: 5 -> Feedrate: 30.0)
(Tool: 6 -> Feedrate: 30.0)
(Tool: 7 -> Feedrate: 30.0)
(Tool: 8 -> Feedrate: 30.0)
(Tool: 9 -> Feedrate: 30.0)

(FEEDRATE RAPIDS: )
(Tool: 1 -> Feedrate Rapids: 1500)
(Tool: 2 -> Feedrate Rapids: 1500)
(Tool: 3 -> Feedrate Rapids: 1500)
(Tool: 4 -> Feedrate Rapids: 1500)
(Tool: 5 -> Feedrate Rapids: 1500)
(Tool: 6 -> Feedrate Rapids: 1500)
(Tool: 7 -> Feedrate Rapids: 1500)
(Tool: 8 -> Feedrate Rapids: 1500)
(Tool: 9 -> Feedrate Rapids: 1500)

(Z_CUT: )
(Tool: 1 -> Z_Cut: -1.7)
(Tool: 2 -> Z_Cut: -1.7)
(Tool: 3 -> Z_Cut: -1.7)
(Tool: 4 -> Z_Cut: -1.7)
(Tool: 5 -> Z_Cut: -1.7)
(Tool: 6 -> Z_Cut: -1.7)
(Tool: 7 -> Z_Cut: -1.7)
(Tool: 8 -> Z_Cut: -1.7)
(Tool: 9 -> Z_Cut: -1.7)

(Tools Offset: )
(Tool: 9 -> Offset Z: -0.0)

(DEPTH_PER_CUT: )
(Tool: 1 -> DeptPerCut: 0.7)
(Tool: 2 -> DeptPerCut: 0.7)
(Tool: 3 -> DeptPerCut: 0.7)
(Tool: 4 -> DeptPerCut: 0.7)
(Tool: 5 -> DeptPerCut: 0.7)
(Tool: 6 -> DeptPerCut: 0.7)
(Tool: 7 -> DeptPerCut: 0.7)
(Tool: 8 -> DeptPerCut: 0.7)
(Tool: 9 -> DeptPerCut: 0.7)

(Z_MOVE: )
(Tool: 1 -> Z_Move: 2)
(Tool: 2 -> Z_Move: 2)
(Tool: 3 -> Z_Move: 2)
(Tool: 4 -> Z_Move: 2)
(Tool: 5 -> Z_Move: 2)
(Tool: 6 -> Z_Move: 2)
(Tool: 7 -> Z_Move: 2)
(Tool: 8 -> Z_Move: 2)
(Tool: 9 -> Z_Move: 2)

(Z Start: None mm)
(Z End: 2.0 mm)
(Steps per circle: 64)
(Preprocessor Excellon: default)

(X range:    5.0547 ...   62.9517  mm)
(Y range:    4.3184 ...   89.0514  mm)

(Spindle Speed: None RPM)
G21
G90
G94



G00 Z2.0000

G01 F30.00
M03
G00 X42.4377 Y10.2484
G01 Z-0.7000
G01 Z0
G00 Z2.0000
G01 Z-1.4000
G01 Z0
G00 Z2.0000
G01 Z-1.7000
G01 Z0
G00 Z2.0000
G00 X42.4377 Y5.1684
G01 Z-0.7000
G01 Z0
G00 Z2.0000
G01 Z-1.4000
G01 Z0
G00 Z2.0000
G01 Z-1.7000
G01 Z0
G00 Z2.0000
G00 X47.5177 Y5.1684
G01 Z-0.7000
G01 Z0
G00 Z2.0000
G01 Z-1.4000
G01 Z0
G00 Z2.0000
G01 Z-1.7000
G01 Z0
G00 Z2.0000
G00 X47.5177 Y10.2484
G01 Z-0.7000
G01 Z0
G00 Z2.0000
G01 Z-1.4000
G01 Z0
G00 Z2.0000
G01 Z-1.7000
G01 Z0
G00 Z2.0000
G00 X47.8477 Y83.1214
G01 Z-0.7000
G01 Z0
G00 Z2.0000
G01 Z-1.4000
G01 Z0
G00 Z2.0000
G01 Z-1.7000
G01 Z0
G00 Z2.0000
G00 X47.8477 Y88.2014
G01 Z-0.7000
G01 Z0
G00 Z2.0000
G01 Z-1.4000
G01 Z0
G00 Z2.0000
G01 Z-1.7000
G01 Z0
G00 Z2.0000
G00 X42.7677 Y88.2014
G01 Z-0.7000
G01 Z0
G00 Z2.0000
G01 Z-1.4000
G01 Z0
G00 Z2.0000
G01 Z-1.7000
G01 Z0
G00 Z2.0000
G00 X42.7677 Y83.1214
G01 Z-0.7000
G01 Z0
G00 Z2.0000
G01 Z-1.4000
G01 Z0
G00 Z2.0000
G01 Z-1.7000
G01 Z0
G00 Z2.0000
M05
G00 Z2.00
G00 X0.0 Y0.0

