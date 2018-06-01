@app.route('/')
def index():
    return 'Ready to roll...'

@app.route('/device/samples', methods=['GET'])
def samples():
    '''Get all samples recorded
    
    Only accept GET verb

    Returns:
        list of recorded samples
    '''
    return 'Previous samples....'

@app.route('/device/register', methods=['POST'])
def register():
    '''Register device using chip_id

    Returns:
        If new device, register and return uuid and current configuration.
        If device already registered, save keepalive and return current configuration.
    
    '''
    return 'Register new device'
