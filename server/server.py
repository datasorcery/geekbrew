from flask import Flask
from flask import request
import datetime
import json

app = Flask(__name__)

@app.route('/device/sample', methods=['POST'])
def sample():
    '''Save one device sample 
    
    Only accept POST verb
    '''
    # Load JSON Data
    data = request.get_json()

    # Save to log
    filename = "{}_data.txt".format(datetime.datetime.utcnow().strftime("%Y%m%d"))
    with open(filename, 'a') as outfile:
        json.dump(data, outfile, ensure_ascii=False)
        outfile.write('\n')
        #print('', file=outfile)
    
    return('OK!\n')