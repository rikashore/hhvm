<?hh
<<__EntryPoint>> function main(): void {
$dom = new DOMDocument();
$comment = $dom->createComment('test-comment');
$comment->appendData('-more-data');
$dom->appendChild($comment);
$dom->saveXML();
echo $dom->saveXML();
}
