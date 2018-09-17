import 'package:flutter/material.dart';
import 'dart:async';

//ControlScreen is a view for when the app is connected to a device
class ControlScreen extends StatefulWidget {
  @override
  ControlScreenState createState() => ControlScreenState();
}

class ControlScreenState extends State<ControlScreen> {
  bool _isConnected = false;

  //Use Flutterblue to scan for devices
  //Currently just swaps to connected view
  _startScan() {
    setState(() {_isConnected = true;});
  }

  Widget _buildControlBody() {
    if(_isConnected) {
      return Center(
        child: Text("Connected to Device"),
      );
    }
    else {
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
      floatingActionButton: _isConnected ? null:FloatingActionButton(
        child: Icon(Icons.search),
        onPressed: _startScan,

      ),
      body: _buildControlBody(),
    );
  }
}