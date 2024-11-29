void MainWindow::on_tabWidget_tabBarClicked(int index) {
    if (index == 2) {
        // Создание окна text_edit
        TextEditWindow *textEditWindow = new TextEditWindow(this);
        textEditWindow->setAttribute(Qt::WA_DeleteOnClose);

        // Создаём экземпляр GraphicsEditorWindow и добавляем в textEdit
        GraphicsEditorWindow *editorWindow = new GraphicsEditorWindow(textEditWindow);
        editorWindow->setParent(textEditWindow);  // Устанавливаем родительский виджет
        editorWindow->setWindowFlags(Qt::Widget);  // Убираем флаги окна, чтобы он встроился

        // Добавляем GraphicsEditorWindow в центральный виджет textEditWindow
        textEditWindow->setCentralWidget(editorWindow);

        // Показываем окно text_edit
        textEditWindow->show();
    }
}
