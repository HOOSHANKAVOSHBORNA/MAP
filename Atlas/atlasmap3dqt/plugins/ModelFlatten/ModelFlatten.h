﻿#pragma once
#include <QtPlugin>
#include <DrawSurfacePolygon/DrawSurfacePolygon.h>

#include <QStringList>
#include <QMap>
typedef std::vector<osg::ref_ptr<osg::Node>> nodeList;

namespace osg {
	class MatrixTransform;
}

QT_BEGIN_NAMESPACE
class QToolBar;
class QAction;
class QMenu;
QT_END_NAMESPACE

class ModelFlatten : public DrawSurfacePolygon
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "io.tqjxlm.Atlas.PluginInterface" FILE "ModelFlatten.json")
	Q_INTERFACES(PluginInterface)

public:
	ModelFlatten();
	~ModelFlatten();
	virtual void setupUi(QToolBar *toolBar, QMenu *menu) override;

  virtual void loadContextMenu(QMenu * contextMenu, QTreeWidgetItem * selectedItem) override;

protected:
	virtual void onLeftButton();
	virtual void onDoubleClick();

protected:
	osg::ref_ptr<osg::Vec2Array> _boundary;
	double _avgHeight;

  // A list of temporary files generated by the flatten process
  // It can be saved or deleted after program exits
  QMap<QString, QStringList> _tempFileList;

signals:
  void startProcess(osg::Group*, QStringList, osg::Vec2Array*, double);

private:
  osg::Group* _selectedNode = NULL;
  QAction* _action;
};