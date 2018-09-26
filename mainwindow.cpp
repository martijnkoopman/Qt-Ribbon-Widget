/*
 * Copyright (C) Martijn Koopman
 * All Rights Reserved
 *
 * This software is distributed WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // Hide ribbon dock title bar
  ui->ribbonDockWidget->setTitleBarWidget(new QWidget());

  // Add tabs to ribbon
  ui->ribbonTabWidget->addTab(QIcon(":/icons/briefcase_1.svg"), "Project");
  ui->ribbonTabWidget->addTab(QIcon(":/icons/monitor_1.svg"), "View");
  ui->ribbonTabWidget->addTab(QIcon(":/icons/engineering_1.svg"), "Tools");
  ui->ribbonTabWidget->addTab(QIcon(":/icons/information_1.svg"), "Help");

  // Add 'Open project' button
  QToolButton *openProjectButton = new QToolButton;
  openProjectButton->setText(tr("Open"));
  openProjectButton->setToolTip(tr("Open existing project"));
  openProjectButton->setIcon(QIcon(":/icons/live_folder_2.svg"));
  openProjectButton->setEnabled(true);
  ui->ribbonTabWidget->addButton("Project", "Project", openProjectButton);

  // Add 'New project' button
  QToolButton *newProjectButton = new QToolButton;
  newProjectButton->setText(tr("New"));
  newProjectButton->setToolTip(tr("Create new project"));
  newProjectButton->setIcon(QIcon(":/icons/create_new_2.svg"));
  newProjectButton->setEnabled(true);
  ui->ribbonTabWidget->addButton("Project", "Project", newProjectButton);

  // Add 'Save project' button
  QToolButton *saveProjectButton = new QToolButton;
  saveProjectButton->setText(tr("Save"));
  saveProjectButton->setToolTip(tr("Save project"));
  saveProjectButton->setIcon(QIcon(":/icons/save_2.svg"));
  saveProjectButton->setEnabled(false);
  ui->ribbonTabWidget->addButton("Project", "Project", saveProjectButton);

  // Add 'Open file' button
  QToolButton *openFileButton = new QToolButton(this);
  openFileButton->setText(tr("File"));
  openFileButton->setToolTip(tr("Open file or directory"));
  openFileButton->setIcon(QIcon(":/icons/add_folder_2.svg"));

  // Add dropdown menu to button
  openFileButton->setPopupMode(QToolButton::MenuButtonPopup);
  QMenu *menu = new QMenu("Title");
  //menu->addAction(QIcon(":/icons/folder_2.svg"),
  //                "Recent directory");
  menu->addAction(QIcon(":/icons/file_2.svg"), "Recent file 1");
  menu->addAction(QIcon(":/icons/file_2.svg"), "Recent file 2");
  menu->addAction(QIcon(":/icons/file_2.svg"), "Recent file 3");
  openFileButton->setMenu(menu);

  ui->ribbonTabWidget->addButton("Project", "Import", openFileButton);

  // Add 'Open database' button
  QToolButton *openDatabaseButton = new QToolButton;
  openDatabaseButton->setText(tr("Database"));
  openDatabaseButton->setToolTip(tr("Connect to database"));
  openDatabaseButton->setIcon(QIcon(":/icons/add_database_2.svg"));
  ui->ribbonTabWidget->addButton("Project", "Import", openDatabaseButton);


  // Add 'Connect to web service' button
  QToolButton *connectWebserviceButton = new QToolButton;
  connectWebserviceButton->setText(tr("Web service"));
  connectWebserviceButton->setToolTip(tr("Connect to web service"));
  connectWebserviceButton->setIcon(QIcon(":/icons/add_link_2.svg"));
  ui->ribbonTabWidget->addButton("Project", "Import", connectWebserviceButton);
}

MainWindow::~MainWindow()
{
  delete ui;
}
