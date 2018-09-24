import 'package:flutter/material.dart';
import 'dart:async';
import 'dart:math';
import 'LogListTile.dart';

//ControlScreen is a view for when the app is connected to a device
class ControlScreen extends StatefulWidget {
  @override
  ControlScreenState createState() => ControlScreenState();
}

class ControlScreenState extends State<ControlScreen> {
  bool _isConnected = false;
  final _measurementList = [
    [0.0, 0.0, 0.0, 0, 0]
  ];
  //For Testing
  //Todo: remove this
  final rng = Random(1234);

  //Use Flutter Blue to scan for devices
  //Currently just swaps to connected view
  //Todo: Replace with appropriate calls to FlutterBlue
  _startScan() {
    setState(() {
      _isConnected = true;
    });
  }

  _takeMeasurement() {
    setState(() {
      _measurementList.add([
        rng.nextDouble() * 360.0,
        rng.nextDouble() * 2.0,
        rng.nextDouble() * 90.0,
        rng.nextInt(3),
        _measurementList.length
      ]);
    });
  }
  //Todo: Improve message for null measurement
  //Todo: Consult with Matt on the formatting.
  //Todo: use tuples and/or add try/catch block

  Widget _buildControlBody() {
    if (_isConnected) {
      //Todo: Replace with control interface.

      return
        ListView(
          shrinkWrap: true,
          reverse: true,
          children: _measurementList
              .map((measurement) => LogListTile(measurement[0], measurement[1],
                  measurement[2], measurement[3], measurement[4]))
              .toList(),
        )
      ;
    } else {
      //Todo: Style home screen
      return Center(
        child: Text("Welcome to GeoApp"),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("Geology App")),
      floatingActionButton: _isConnected
          ? FloatingActionButton(
              child: Icon(Icons.explore),
              onPressed: _takeMeasurement,
            )
          : FloatingActionButton(
              child: Icon(Icons.search),
              onPressed: _startScan,
            ),
      body: _buildControlBody(),
    );
  }
}
