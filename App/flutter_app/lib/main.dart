import 'package:flutter/material.dart';
import 'widgets.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "GeoApp Demo",
      home: ControlScreen(),
    );
  }
}