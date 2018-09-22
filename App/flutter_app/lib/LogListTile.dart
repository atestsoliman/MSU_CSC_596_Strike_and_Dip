import 'package:flutter/material.dart';


class LogListTile extends StatelessWidget{
  final double north;
  final double sigma;
  final double dip;
  final int quadrant;
  final int id;

  const LogListTile(this.north, this.sigma, this.dip, this.quadrant, this.id);

  _displayQuad(int q) {
    switch(q) {
      case 0: return "NE";
      case 1: return "SE";
      case 2: return "SW";
      case 3: return "NW";
    }
  }
  @override
  Widget build(BuildContext context) {
    return ListTile(title: Text('N: ${north.toStringAsFixed(2)}\u00b0 \n Uncertaniy   ${sigma.toStringAsFixed(2)}\u03c3     '
        '\nDip: ${dip.toStringAsFixed(2)}' '\nQuad= ${_displayQuad(quadrant)}    '
        '\nID: ${id.toString().padLeft(4, '0')}'));
  }


}
