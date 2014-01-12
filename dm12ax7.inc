* 12AX7A Triode PSpice Model                     8/96, Rev. 1.0  (fp)
*
* -------------------------------------------------------------------
*  This model is provided "as is", with no warranty of any kind,
*  either expressed or implied, about the suitability or fitness
*  of this model for any particular purpose.  Use of this model
*  shall be entirely at the user's own risk.
*
*  For a discussion about vacuum tube modeling please refer to:
*  W. Marshall Leach, jr: "SPICE Models for Vacuum-Tube Amplifiers";
*  J. Audio Eng. Soc., Vol 43, No 3, March 1995.
* -------------------------------------------------------------------
*
* This model is valid for the following tubes:
* 12AX7A/ECC83, 7025, 6EU7, 6681, 6AV6, 12DW7/7247 (Unit #1);
* at the following conditions:
*  Plate voltage  : 25..400V
*  Grid voltage   : 0..-3.5V
*  Cathode current: 0..8mA
*
* Modified DM 28/4/97
*
*  1 Model modified to cut anode draw below va=5v. E2 is anode draw
*    multiplier.
*
*  2 Grid current simulation added.  Based on VA=100V taken from
*    measurements.  No attempt is made to model at different VA or
*    model the effects of secondary emission. E3 denotes the amount
*    of grid current.
*
*
* Connections: Plate
*              | Grid
*              | | Cathode
*              | | |
.SUBCKT 12AX7A P G K
E1  2  0  VALUE={45+V(P,K)+95.43*V(G,K)}
E2  3  0  VALUE={LIMIT{V(P,K)/5,0,1}}
E3  4  0  VALUE={1E-6*PWR(LIMIT{V(G,K)+2,0,9999},1.5)}
R1  2  0  1.0K
Gp  P  K  VALUE={V(3)*1.147E-6*(PWR(V(2),1.5)+PWRS(V(2),1.5))/2}
Gg  G  K  VALUE={V(4)}
Cgk G  K  1.6P
Cgp G  P  1.7P
Cpk P  K  0.46P
.ENDS 12AX7A
