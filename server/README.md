# Log Server

## Development

* source venv/bin/activate
* export FLASK_APP=server.py
* export FLASK_ENV=development
* flask run or flask run --host=0.0.0.0

## CURL Test

* curl -H "Content-Type: application/json" --request POST --data-binary @sample.json localhost:5000/device/sample

## Routes

* /



