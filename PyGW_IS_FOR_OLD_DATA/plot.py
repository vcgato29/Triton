"""
This submodule specializes the usual pyplot.plot function to be used
as methods with Waveform objects.

"""

TypeDict = {
    "rMPsi4" : r'r M \Psi_4',
    "rhdot" : r'r \dot{h}',
    "rhOverM" : r'r h / M',
    "rPsi4" : r'r \Psi_4',
    "rhdot" : r'r \dot{h}',
    "rh" : r'r h',
    "MPsi4" : r'M \Psi_4',
    "hdot" : r'\dot{h}',
    "hOverM" : r'h/M',
    "Psi4" : r'\Psi_4',
    "hdot" : r'\dot{h}',
    "h": r'h'
    }


from matplotlib.pyplot import plot as matplotlibpyplotplot
from matplotlib.pyplot import semilogx as matplotlibpyplotsemilogx
from matplotlib.pyplot import semilogy as matplotlibpyplotsemilogy
from matplotlib.pyplot import loglog as matplotlibpyplotloglog
from matplotlib.pyplot import xlabel, ylabel, setp
try :
    from matplotlib.pyplot import tight_layout
except :
    pass
from matplotlib.pyplot import isinteractive, ioff, ion, draw, show, gcf
import matplotlib as mpl
try:
    mpl.rcParams['axes.color_cycle'] = ['#000000', '#cc79a7', '#d55e00', '#0072b2', '#f0e442', '#56b4e9', '#e69f00', '#2b9f78']
except KeyError :
    mpl.axes.set_default_color_cycle(['#000000', '#cc79a7', '#d55e00', '#0072b2', '#f0e442', '#56b4e9', '#e69f00', '#2b9f78'])
from warnings import warn
from numpy import array, empty, transpose, sin, cos

def NotAbs(Anything) :
    return Anything

def plotWaveform(this, WaveformPart='Mag', Modes=(), *pyplot_args, **pyplot_kwargs) :
    """
    This function should be called as a method of the Waveform class,
    e.g., as
    
    >>> W.plot('Mag', Modes=[[2,2], [2,-2]], c='r')
    
    where W is a Waveform object.  The first parameter should be a
    string --- one of ['Mag', 'LogMag', 'LogLogMag', 'Arg', 'LogArg',
    'Re', Im'].  The second (optional) parameter is a list (using
    square brackets), where each element is some [l,m].  Only modes
    included in this list will be plotted, unless the list is empty
    (the default), in which case all modes are plotted.
    
    All following arguments are passed to the usual pyplot.plot (or
    semilogx, semilogy, or loglog) function; in the example above, the
    "c='r'" argument is passed, making the line color red.  The only
    exception to this rule is the "label" keyword, which is handled
    internally when there is just one line.  Otherwise, the legend
    labels are set automatically to contain the [l,m] mode (though the
    legend is not shown by default).
    
    """
    
    XLabel = r'$(t-r_\ast)/M$'
    YLabel = ''
    
    Labels = []
    Lines = []
    
    def Re(ModeIndex) :
        return this.Mag(ModeIndex) * cos(this.Arg(ModeIndex))
    
    def Im(ModeIndex) :
        return this.Mag(ModeIndex) * sin(this.Arg(ModeIndex))
    
    WasInteractive = isinteractive()
    ioff()
    
    ## This decides which quantity to plot, what type of plot, and what the labels should be
    if (WaveformPart.lower()=='mag') :
        YLabel =r'$\mathrm{Mag} \left( ' + TypeDict[this.Type()] + r' \right) $'
        styledplot = matplotlibpyplotplot
        quantity = this.Mag
        AbsOrNot = NotAbs
    elif (WaveformPart.lower()=='logmag') :
        YLabel =r'$\mathrm{Mag} \left( ' + TypeDict[this.Type()] + r' \right) $'
        styledplot = matplotlibpyplotsemilogy
        quantity = this.Mag
        AbsOrNot = abs
    elif (WaveformPart.lower()=='loglogmag') :
        YLabel =r'$\mathrm{Mag} \left( ' + TypeDict[this.Type()] + r' \right) $'
        styledplot = matplotlibpyplotloglog
        quantity = this.Mag
        AbsOrNot = abs
    elif (WaveformPart.lower()=='arg') :
        YLabel =r'$\mathrm{Arg} \left( ' + TypeDict[this.Type()] + r' \right) $'
        styledplot = matplotlibpyplotplot
        quantity = this.Arg
        AbsOrNot = NotAbs
    elif (WaveformPart.lower()=='logarg') :
        YLabel =r'$\mathrm{Arg} \left( ' + TypeDict[this.Type()] + r' \right) $'
        styledplot = matplotlibpyplotsemilogy
        quantity = this.Arg
        AbsOrNot = abs
    elif (WaveformPart.lower()=='real' or WaveformPart.lower()=='re') :
        YLabel =r'$\mathrm{Re} \left( ' + TypeDict[this.Type()] + r' \right) $'
        styledplot = matplotlibpyplotplot
        quantity = Re
        AbsOrNot = NotAbs
    elif (WaveformPart.lower()=='imaginary' or WaveformPart.lower()=='imag' or WaveformPart.lower()=='im') :
        YLabel =r'$\mathrm{Im} \left( ' + TypeDict[this.Type()] + r' \right) $'
        styledplot = matplotlibpyplotplot
        quantity = Im
        AbsOrNot = NotAbs
    else :
        print("Unsupported data type %s" % WaveformPart)
        return []
    
    ## This does the actual work of plotting, depending on what Modes are needed
    if (type(Modes)==int) : # The requested mode is plotted
        Lines = styledplot(this.T(), AbsOrNot(quantity(Modes)), *pyplot_args, **pyplot_kwargs)
        Labels = ['(' + str(this.L(Modes)) + ', ' + str(this.M(Modes)) + ')']
    elif (len(Modes)==0) : # All modes are plotted
        Lines = styledplot(this.T(), AbsOrNot(quantity()).transpose(), *pyplot_args, **pyplot_kwargs)
        if ((this.NModes()==1) and ('label' in pyplot_kwargs)) :
            Labels = [pyplot_kwargs['label']]
        else :
            Labels = ['(' + str(this.L(mode)) + ', ' + str(this.M(mode)) + ')' for mode in range(this.NModes())]
    elif ( (len(Modes)==2) and (type(Modes[0])==int and type(Modes[1])==int) ) :
        ModeIndex = this.FindModeIndex(Modes[0], Modes[1])
        Lines = styledplot(this.T(), transpose(AbsOrNot(quantity(ModeIndex))), *pyplot_args, **pyplot_kwargs)
        if ('label' in pyplot_kwargs) :
            Labels = [pyplot_kwargs['label']]
        else :
            Labels = ['(' + str(this.L(ModeIndex)) + ', ' + str(this.M(ModeIndex)) + ')']
    elif ( (len(Modes)==1) and (type(Modes[0])==list) and (type(Modes[0][0])==int and type(Modes[0][1])==int) ) :
        ModeIndex = this.FindModeIndex(Modes[0][0], Modes[0][1])
        Lines = styledplot(this.T(), transpose(AbsOrNot(quantity(ModeIndex))), *pyplot_args, **pyplot_kwargs)
        if ('label' in pyplot_kwargs) :
            Labels = [pyplot_kwargs['label']]
        else :
            Labels = ['(' + str(this.L(ModeIndex)) + ', ' + str(this.M(ModeIndex)) + ')']
    else :
        Modes = array(Modes, dtype=int)
        for i in range(Modes.shape[0]) :
            ModeIndex = this.FindModeIndex(int(Modes[i][0]), int(Modes[i][1]))
            #print(ModeIndex, Modes[i][0], Modes[i][1])
            Labels.append('(' + str(Modes[i][0]) + ', ' + str(Modes[i][1]) + ')')
            Lines.append(styledplot(this.T(), AbsOrNot(quantity(ModeIndex)).transpose(), *pyplot_args, **pyplot_kwargs))
    
    xlabel(XLabel)
    ylabel(YLabel)
    
    draw()
    
    if(WasInteractive) :
        ion()
        gcf().show()
    
    try :
        tight_layout(pad=0.1)
    except :
        pass
    
    for i in range(len(Lines)) :
        setp(Lines[i], label=Labels[i])
    
    return Lines



### The following allows us to write things like
###   W = PyGW_IS_FOR_OLD_DATA.Waveform()
###   W.plot('Mag', ((2,2), (2,-2)))
import PyGW_IS_FOR_OLD_DATA
PyGW_IS_FOR_OLD_DATA.Waveform.plot = plotWaveform
