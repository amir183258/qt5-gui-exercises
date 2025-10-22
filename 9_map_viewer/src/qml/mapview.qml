import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15

Item
{
	id: window

	Plugin
	{
		id: mapPlugin
		name: "osm"
	}

	Image
	{
		id: icon
		source: "qrc:///images/map_marker_icon.png"
		sourceSize.width: 50
		sourceSize.height: 50
	}

	MapQuickItem
	{
		id: marker
		anchorPoint.x: marker.width / 4
		anchorPoint.y: marker.height
		coordinate: QtPositioning.coordinate(40.7274175, -73.99835)

		sourceItem: icon
	}

	Map
	{
		id: map
		anchors.fill: parent
		plugin: mapPlugin
		center: QtPositioning.coordinate(40.7264175, -73.99735)
		zoomLevel: 14

		Component.onCompleted:
		{
			map.addMapItem(marker)
		}
	}
}
