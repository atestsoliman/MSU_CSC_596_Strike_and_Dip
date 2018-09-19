import 'package:flutter/material.dart';
import 'dart:async';
import 'dart:math';

//ControlScreen is a view for when the app is connected to a device
class ControlScreen extends StatefulWidget {
  @override
  ControlScreenState createState() => ControlScreenState();
}

class ControlScreenState extends State<ControlScreen> {
  bool _isConnected = false;
  final _measurementList = [[0,0]];
  //For Testing
  //Todo: remove this
  final rng = Random(1234);


  //Use Flutter Blue to scan for devices
  //Currently just swaps to connected view
  //Todo: Replace with appropriate calls to FlutterBlue
  _startScan() {
    setState(() {_isConnected = true;});
  }
  _takeMeasurement() {
    setState(() {
      _measurementList.add([rng.nextInt(360), rng.nextInt(180)]);
    });
  }
  //Todo: Improve message for null measurement
  //Todo: Consult with Matt on the formatting.
  //Todo: use tuples and/or add try/catch block
  String _printMeasurement(_lastMeasurement) {
      return 'N ${_lastMeasurement[0]}\u00b0, Dip ${_lastMeasurement[1]}\u00b0';
  }


  Widget _buildControlBody() {
    if(_isConnected) {
      //Todo: Replace with control interface.

      return Column(
        children: <Widget>[
          Text("Connected to Device"),
          ListBody(
            reverse: true,
            children: _measurementList.map((measurement) => ListTile(title: Text(_printMeasurement(measurement)))).toList(),
          )
      ]);
    }
    else {
      //Todo: Style home screen
      return Center(
        child: Text("Welcome to GeoApp"),
      );
    }
  }
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Geology App")
      ),
      floatingActionButton: _isConnected ? FloatingActionButton(
        child: Icon(Icons.explore),
        onPressed: _takeMeasurement,
      ):FloatingActionButton(
        child: Icon(Icons.search),
        onPressed: _startScan,

      ),
      body: _buildControlBody(),
    );
  }
}